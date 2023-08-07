#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFFER_SIZE 64

/**
 * validate_arguments - Validates the command-line arguments.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success, -1 on failure.
 */
int validate_arguments(int argc, char *argv[]);

/**
 * open_elf_file - Opens the ELF file for reading.
 * @filename: The name of the ELF file.
 * Return: The file descriptor on success, -1 on failure.
 */
int open_elf_file(const char *filename);

/**
 * display_elf_header - Displays the information contained in the ELF header.
 * @fd: The file descriptor of the ELF file.
 */
void display_elf_header(int fd);

int main(int argc, char *argv[])
{
    int fd;

    if (validate_arguments(argc, argv) == -1)
        return (98);

    fd = open_elf_file(argv[1]);
    if (fd == -1)
        return (98);

    display_elf_header(fd);

    close(fd);
    return (0);
}

int validate_arguments(int argc, char *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return (-1);
    }
    return (0);
}

int open_elf_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
    return (fd);
}

void display_elf_header(int fd)
{
    Elf64_Ehdr header;
    ssize_t bytes_read;

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Can't read ELF header\n");
        exit(98);
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", header.e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');

    printf("  Class:                             ");
    switch (header.e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:  printf("ELFCLASSNONE\n");  break;
        case ELFCLASS32:    printf("ELF32\n");         break;
        case ELFCLASS64:    printf("ELF64\n");         break;
        default:            printf("<unknown>\n");    break;
    }

    printf("  Data:                              ");
    switch (header.e_ident[EI_DATA])
    {
        case ELFDATANONE:   printf("ELFDATANONE\n");   break;
        case ELFDATA2LSB:   printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB:   printf("2's complement, big endian\n");    break;
        default:            printf("<unknown>\n");    break;
    }

    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:         printf("UNIX - System V\n");     break;
        case ELFOSABI_NETBSD:       printf("UNIX - NetBSD\n");       break;
        case ELFOSABI_LINUX:        printf("UNIX - Linux\n");        break;
        case ELFOSABI_SOLARIS:      printf("UNIX - Solaris\n");      break;
        default:                    printf("<unknown: %d>\n", header.e_ident[EI_OSABI]); break;
    }

    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header.e_type)
    {
        case ET_NONE:    printf("NONE (No file type)\n");         break;
        case ET_REL:     printf("REL (Relocatable file)\n");      break;
        case ET_EXEC:    printf("EXEC (Executable file)\n");      break;
        case ET_DYN:     printf("DYN (Shared object file)\n");    break;
        case ET_CORE:    printf("CORE (Core file)\n");            break;
        default:         printf("<unknown>\n");                   break;
    }

    printf("  Entry point address:               %#lx\n", (unsigned long)header.e_entry);
}

