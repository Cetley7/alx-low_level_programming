#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <elf.h>
#include <stddef.h>

void print_error(const char *message);
void print_magic(unsigned char *magic);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_os_abi(unsigned char osabi);
void print_abi_version(unsigned char abiversion);
void print_type(unsigned short type);
void print_entry_point(Elf64_Addr entry);
void display_elf_header(const char *filename);

#endif /* ELF_HEADER_H */

