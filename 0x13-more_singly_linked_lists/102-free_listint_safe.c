#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * free_listint_safe - Frees a listint_t list, even if it contains a loop.
 * @h: Double pointer to the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;

	/* Traverse the list and free each node */
	while (current != NULL)
	{
		size++;
		temp = current;
		current = current->next;
		free(temp);

		/* Break the loop if we reach a node we have already visited */
		if (current == *h)
		{
			*h = NULL; /* Set the head to NULL to avoid using a dangling pointer */
			break;
		}
	}

	return (size);
}

