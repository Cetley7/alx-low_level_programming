#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void display_elf_header(const char *filename);
void display_magic(const unsigned char *magic);
void display_class(uint8_t e_ident_class);
void display_data(uint8_t e_ident_data);
void display_version(uint8_t e_ident_version);
void display_os_abi(uint8_t e_ident_osabi);
void display_abi_version(uint8_t e_ident_abiversion);
void display_type(uint16_t e_type);
void display_entry(uint64_t e_entry);


#endif /* MAIN_H */

