#ifndef MAIN_H
#define MAIN_H

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int find_length(char *str);
char *create_array(int size);
char *iterate_zeros(char *str);
int get_digit(char c);
void get_product(char *product, char *multiplicand, int digit, int zeros);
void add_numbers(char *final_product, char *next_product, int next_length);
#endif /* MAIN_H */

