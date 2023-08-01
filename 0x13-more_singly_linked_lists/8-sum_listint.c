#include <stddef.h>
#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t.
 * @head: Pointer to the head node of the linked list.
 *
 * Return: Sum of all the data (n) of the linked list, or 0.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}

