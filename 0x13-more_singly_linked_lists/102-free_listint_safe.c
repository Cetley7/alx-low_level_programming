#include "lists.h"
#include <stdlib.h> /* For free */

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *temp;
	size_t size = 0;

	while (current != NULL)
	{
		size++;
		temp = current;
		current = current->next;
		free(temp);
		if (temp <= current)
		{
			*h = NULL;
			break;
		}
	}

	return (size);
}

