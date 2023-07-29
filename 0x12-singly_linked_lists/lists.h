#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

/* Function prototype to print all elements of the list */
size_t print_list(const list_t *h);

/* Function prototype to get the number of elements in the list */
size_t list_len(const list_t *h);

/* Function prototype to add a new node at the beginning of the list */
list_t *add_node(list_t **head, const char *str);

/* Function prototype to add a new node at the end of the list */
list_t *add_node_end(list_t **head, const char *str);

/* Function prototype to free a list */
void free_list(list_t *head);

#endif /* LISTS_H */

