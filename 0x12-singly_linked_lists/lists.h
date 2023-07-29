#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Structure for the linked list */
typedef struct list_s
{
    char *str;
    int len;
    struct list_s *next;
} list_t;

/* Function prototype for add_node */
list_t *add_node(list_t **head, const char *str);

#endif /* LISTS_H */

