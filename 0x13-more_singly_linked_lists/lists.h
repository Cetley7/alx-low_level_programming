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

/* Function to add a new node at the beginning of the list */
listint_t *add_nodeint(listint_t **head, const int n);

/* Function to add a new node at the end of the list */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* Function to free a listint_t list */
void free_listint(listint_t *head);

/* Function to free a listint_t list and set head to NULL */
void free_listint2(listint_t **head);

/* Function to delete the head node and return its data */
int pop_listint(listint_t **head);

/* Function to get the nth node of the list */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/* Function to calculate the sum of all data (n) in the list */
int sum_listint(listint_t *head);

/* Function to insert a new node at a given position */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

/* Function prototypes */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

#endif /* LISTS_H */

