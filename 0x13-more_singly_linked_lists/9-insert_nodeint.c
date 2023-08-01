#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * insert_nodeint_at_index - Inserts a new node in the list.
 * @head: Double pointer to the head of the list.
 * @idx: Index where the new node should be added (starts at 0).
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	if (head == NULL)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	listint_t *current = *head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == idx - 1)
		{
			new_node->n = n;
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}

		current = current->next;
		count++;
	}

	free(new_node); /* Free the allocated memory if index is not found */
	return (NULL);
}

