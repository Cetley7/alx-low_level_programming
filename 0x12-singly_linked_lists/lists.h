#ifndef LISTS_H
#define LISTS_H

/* Other necessary includes and structures go here */

/* Structure for the linked list */
typedef struct list_s
{
    char *str;
    int len;
    struct list_s *next;
} list_t;

/* Function prototype for print_list */
size_t print_list(const list_t *h);

#endif /* LISTS_H */

