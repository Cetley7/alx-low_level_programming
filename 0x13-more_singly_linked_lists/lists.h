#ifndef LISTS_H
#define LISTS_H

#include <stddef.h> /* For size_t */

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* Function to print all elements of a list */
size_t print_listint(const listint_t *h);

/* Function to return the number of elements in a list */
size_t listint_len(const listint_t *h);

#endif /* LISTS_H */

