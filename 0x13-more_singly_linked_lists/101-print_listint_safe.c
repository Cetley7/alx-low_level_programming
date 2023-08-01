#include "lists.h"
#include <stdio.h> /* for printf */
#include <stdlib.h> /* for exit */

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t node_count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		/* Move slow by one node and fast by two nodes */
		slow = slow->next;
		fast = fast->next->next;

		/* Check if we found a loop */
		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)fast, fast->n);
			exit(98);
		}

		/* Print the current node */
		printf("[%p] %d\n", (void *)slow, slow->n);
		node_count++;
	}

	/* Print the last node (if it exists) */
	if (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		node_count++;
	}

	return (node_count);
}

