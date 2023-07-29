#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Structure for the linked list */
typedef struct list_s
{
    char *str;
    struct list_s *next;
} list_t;

/* Function prototypes */
list_t *add_node(list_t **head, const char *str);
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);

#endif /* LISTS_H */

