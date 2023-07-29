#ifndef LISTS_H
#define LISTS_H

/* Structure for the linked list */
typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

/* Function to add a new node at the beginning of the list */
list_t *add_node(list_t **head, const char *str);

#endif /* LISTS_H */

