#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error_exit - Prints an error message and exits with status code 98.
 * @msg: The error message to display.
 */
void error_exit(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * display_elf_header - Reads and displays information from the ELF header.
 * @elf_fd: File descriptor of the ELF file.
 */
void display_elf_header(int elf_fd)
{
	Elf64_Ehdr elf_header;

	if (read(elf_fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
		error_exit("Unable to read ELF header");

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Not an ELF file");

	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header.e_ident[i]);
	printf("\n");

	printf("  Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
	printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" : "Other");
	printf("  Entry point address:               %#lx\n", (unsigned long)elf_header.e_entry);
}

int main(int argc, char *argv[])
{
	int elf_fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	elf_fd = open(argv[1], O_RDONLY);
	if (elf_fd == -1)
		error_exit("Unable to open ELF file");

	display_elf_header(elf_fd);

	close(elf_fd);
	return (0);
}

