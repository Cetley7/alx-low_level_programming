#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"

#define BUFFER_SIZE 64

void display_elf_header(const char *filename);
void display_magic(const unsigned char *magic);
void display_class(uint8_t e_ident_class);
void display_data(uint8_t e_ident_data);
void display_version(uint8_t e_ident_version);
void display_os_abi(uint8_t e_ident_osabi);
void display_abi_version(uint8_t e_ident_abiversion);
void display_type(uint16_t e_type);
void display_entry(uint64_t e_entry);

/**
 * main - Displays information from the ELF header of an ELF file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	display_elf_header(argv[1]);

	return (0);
}

/**
 * display_elf_header - Displays ELF header information.
 * @filename: The name of the ELF file.
 */
void display_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open %s\n", filename);
		exit(98);
	}

	Elf64_Ehdr elf_header;
	ssize_t bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr))
	{
		fprintf(stderr, "Error: Unable to read ELF header\n");
		close(fd);
		exit(98);
	}

	display_magic(elf_header.e_ident);
	display_class(elf_header.e_ident[EI_CLASS]);
	display_data(elf_header.e_ident[EI_DATA]);
	display_version(elf_header.e_ident[EI_VERSION]);
	display_os_abi(elf_header.e_ident[EI_OSABI]);
	display_abi_version(elf_header.e_ident[EI_ABIVERSION]);
	display_type(elf_header.e_type);
	display_entry(elf_header.e_entry);

	close(fd);
}

/**
 * display_magic - Displays the ELF magic number.
 * @magic: Pointer to the ELF magic number.
 */
void display_magic(const unsigned char *magic)
{
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * display_class - Displays the ELF class.
 * @e_ident_class: The ELF class identifier.
 */
void display_class(uint8_t e_ident_class)
{
	printf("Class:                             ");
	switch (e_ident_class)
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Invalid\n");
		break;
	}
}

/**
 * display_data - Displays the ELF data encoding.
 * @e_ident_data: The ELF data encoding identifier.
 */
void display_data(uint8_t e_ident_data)
{
	printf("Data:                              ");
	switch (e_ident_data)
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid\n");
		break;
	}
}

/**
 * display_version - Displays the ELF version.
 * @e_ident_version: The ELF version identifier.
 */
void display_version(uint8_t e_ident_version)
{
	printf("Version:                           ");
	switch (e_ident_version)
	{
	case EV_CURRENT:
		printf("1 (current)\n");
		break;
	default:
		printf("Invalid\n");
		break;
	}
}

/**
 * display_os_abi - Displays the ELF OS/ABI.
 * @e_ident_osabi: The ELF OS/ABI identifier.
 */
void display_os_abi(uint8_t e_ident_osabi)
{
	printf("OS/ABI:                            ");
	switch (e_ident_osabi)
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_LINUX:
		printf("Linux\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}

/**
 * display_abi_version - Displays the ELF ABI version.
 * @e_ident_abiversion: The ELF ABI version identifier.
 */
void display_abi_version(uint8_t e_ident_abiversion)
{
	printf("ABI Version:                       %d\n", e_ident_abiversion);
}

/**
 * display_type - Displays the ELF file type.
 * @e_type: The ELF file type.
 */
void display_type(uint16_t e_type)
{
	printf("Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}

/**
 * display_entry - Displays the ELF entry point address.
 * @e_entry: The ELF entry point address.
 */
void display_entry(uint64_t e_entry)
{
	printf("Entry point address:               %#018lx\n", e_entry);
}

