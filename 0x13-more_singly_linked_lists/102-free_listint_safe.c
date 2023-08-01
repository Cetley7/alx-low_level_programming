#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list even if it contains a loop.
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h;
	listint_t *fast = *h;
	size_t size = 0;

	if (h == NULL || *h == NULL)
		return (0);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) /* Loop detected */
		{
			/* Move slow to the head, keeping fast at the meeting point */
			slow = *h;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			/* Move both pointers until they meet again at the loop start */
			while (fast->next != slow)
			{
				fast = fast->next;
				size++;
			}
			size++;
			fast->next = NULL;
			break;
		}
	}

	/* Free the rest of the list (if no loop or after removing the loop) */
	while (*h != NULL)
	{
		listint_t *temp = *h;
		*h = (*h)->next;
		free(temp);
		size++;
	}

	return (size);
}

