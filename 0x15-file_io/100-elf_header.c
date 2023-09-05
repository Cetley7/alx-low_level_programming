#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * custom_strncmp - compare two strings
 * @str1: the first string
 * @str2: the second string
 * @num_bytes: the maximum number of bytes to compare
 *
 * Return: 0 if the first num_bytes of str1 and str2 are equal, otherwise non-zero
 */
int custom_strncmp(const char *str1, const char *str2, size_t num_bytes)
{
    for (; num_bytes && *str1 && *str2; --num_bytes, ++str1, ++str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
    }
    if (num_bytes)
    {
        if (*str1)
            return (1);
        if (*str2)
            return (-1);
    }
    return (0);
}

/**
 * custom_close - close a file descriptor and print an error message upon failure
 * @fd: the file descriptor to close
 */
void custom_close(int fd)
{
    if (close(fd) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't close file descriptor\n", 36);
    exit(98);
}

/**
 * custom_read - read from a file and print an error message upon failure
 * @fd: the file descriptor to read from
 * @buf: the buffer to write to
 * @count: the number of bytes to read
 */
void custom_read(int fd, char *buf, size_t count)
{
    if (read(fd, buf, count) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't read from file\n", 28);
    custom_close(fd);
    exit(98);
}

/**
 * print_elf_magic - print ELF magic
 * @header: the ELF header
 */
void print_elf_magic(const unsigned char *header)
{
    unsigned int i;

    if (custom_strncmp((const char *)header, ELFMAG, 4))
    {
        write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
        exit(98);
    }

    printf("ELF Header:\n  Magic:   ");

    for (i = 0; i < 16; ++i)
        printf("%02x%c", header[i], i < 15 ? ' ' : '\n');
}

/**
 * print_elf_class - print ELF class
 * @header: the ELF header
 *
 * Return: bit mode (32 or 64)
 */
size_t print_elf_class(const unsigned char *header)
{
    printf("  %-34s ", "Class:");

    if (header[EI_CLASS] == ELFCLASS64)
    {
        printf("ELF64\n");
        return (64);
    }
    if (header[EI_CLASS] == ELFCLASS32)
    {
        printf("ELF32\n");
        return (32);
    }
    printf("<unknown: %x>\n", header[EI_CLASS]);
    return (32);
}

/**
 * print_elf_data - print ELF data
 * @header: the ELF header
 *
 * Return: 1 if big endian, otherwise 0
 */
int print_elf_data(const unsigned char *header)
{
    printf("  %-34s ", "Data:");

    if (header[EI_DATA] == ELFDATA2MSB)
    {
        printf("2's complement, big endian\n");
        return (1);
    }
    if (header[EI_DATA] == ELFDATA2LSB)
    {
        printf("2's complement, little endian\n");
        return (0);
    }
    printf("Invalid data encoding\n");
    return (0);
}

/**
 * print_elf_version - print ELF version
 * @header: the ELF header
 */
void print_elf_version(const unsigned char *header)
{
    printf("  %-34s %u", "Version:", header[EI_VERSION]);

    if (header[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}

/**
 * print_elf_osabi - print ELF OS/ABI
 * @header: the ELF header
 */
void print_elf_osabi(const unsigned char *header)
{
    const char *os_table[19] = {
        "UNIX - System V",
        "UNIX - HP-UX",
        "UNIX - NetBSD",
        "UNIX - GNU",
        "<unknown: 4>",
        "<unknown: 5>",
        "UNIX - Solaris",
        "UNIX - AIX",
        "UNIX - IRIX",
        "UNIX - FreeBSD",
        "UNIX - Tru64",
        "Novell - Modesto",
        "UNIX - OpenBSD",
        "VMS - OpenVMS",
        "HP - Non-Stop Kernel",
        "AROS",
        "FenixOS",
        "Nuxi CloudABI",
        "Stratus Technologies OpenVOS"
    };

    printf("  %-34s ", "OS/ABI:");

    if (header[EI_OSABI] < 19)
        printf("%s\n", os_table[(unsigned int)header[EI_OSABI]]);
    else
        printf("<unknown: %x>\n", header[EI_OSABI]);
}

/**
 * print_elf_abivers - print ELF ABI version
 * @header: the ELF header
 */
void print_elf_abivers(const unsigned char *header)
{
    printf("  %-34s %u\n", "ABI Version:", header[EI_ABIVERSION]);
}

/**
 * print_elf_type - print ELF type
 * @header: the ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void print_elf_type(const unsigned char *header, int big_endian)
{
    char *type_table[5] = {
        "NONE (No file type)",
        "REL (Relocatable file)",
        "EXEC (Executable file)",
        "DYN (Shared object file)",
        "CORE (Core file)"
    };
    unsigned int type;

    printf("  %-34s ", "Type:");

    if (big_endian)
        type = 0x100 * header[16] + header[17];
    else
        type = 0x100 * header[17] + header[16];

    if (type < 5)
        printf("%s\n", type_table[type]);
    else if (type >= ET_LOOS && type <= ET_HIOS)
        printf("OS Specific: (%4x)\n", type);
    else if (type >= ET_LOPROC && type <= ET_HIPROC)
        printf("Processor Specific: (%4x)\n", type);
    else
        printf("<unknown: %x>\n", type);
}

/**
 * print_elf_entry - print entry point address
 * @header: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */
void print_elf_entry(const unsigned char *header, size_t bit_mode, int big_endian)
{
    int address_size = bit_mode / 8;

    printf("  %-34s 0x", "Entry point address:");

    if (big_endian)
    {
        while (address_size && !*(header))
            --address_size, ++header;

        printf("%x", *header & 0xff);

        while (--address_size > 0)
            printf("%02x", *(++header) & 0xff);
    }
    else
    {
        header += address_size;

        while (address_size && !*(--header))
            --address_size;

        printf("%x", *header & 0xff);

        while (--address_size > 0)
            printf("%02x", *(--header) & 0xff);
    }

    printf("\n");
}

/**
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
    unsigned char header[18];
    unsigned int bit_mode;
    int big_endian;
    int fd;

    if (argc != 2)
    {
        write(STDERR_FILENO, "Usage: custom_elf_header elf_filename\n", 38);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Error: Can't read from file\n", 28);
        exit(98);
    }

    custom_read(fd, (char *)header, 18);

    print_elf_magic(header);
    bit_mode = print_elf_class(header);
    big_endian = print_elf_data(header);
    print_elf_version(header);
    print_elf_osabi(header);
    print_elf_abivers(header);
    print_elf_type(header, big_endian);

    lseek(fd, 24, SEEK_SET);
    custom_read(fd, (char *)header, bit_mode / 8);

    print_elf_entry(header, bit_mode, big_endian);

    custom_close(fd);

    return (0);
}

