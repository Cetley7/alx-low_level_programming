#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * loop_detected - Check if a loop is detected in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, or NULL.
 */
listint_t *loop_detected(listint_t *head)
{
	listint_t *tortoise = head;
	listint_t *hare = head;

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (hare);
		}
	}

	return (NULL);
}

/**
 * remove_loop - Remove the loop from a linked list.
 * @head: Pointer to the head of the list.
 * @loop_start: Pointer to the node where the loop starts.
 */
void remove_loop(listint_t *head, listint_t *loop_start)
{
	listint_t *ptr1 = head;
	listint_t *ptr2 = loop_start;

	while (ptr1->next != ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	ptr2->next = NULL;
}

/**
 * free_listint_safe - Frees a listint_t list even if it contains a loop.
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *loop_start = loop_detected(*h);
	size_t size = 0;

	if (h == NULL || *h == NULL)
		return (0);

	if (loop_start != NULL)
		remove_loop(*h, loop_start);

	while (*h != NULL)
	{
		listint_t *temp = *h;
		*h = (*h)->next;
		free(temp);
		size++;
	}

	return (size);
}

