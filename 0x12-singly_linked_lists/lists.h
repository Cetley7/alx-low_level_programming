#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct list_s - Singly linked list node
 *
 * @str: String stored in the node
 * @len: Length of the string
 * @next: Pointer to the next node
 */
typedef struct list_s
{
	char *str;
	int len;
	struct list_s *next;
} list_t;

/* Function prototypes */
size_t list_len(const list_t *h);

#endif /* LISTS_H */

