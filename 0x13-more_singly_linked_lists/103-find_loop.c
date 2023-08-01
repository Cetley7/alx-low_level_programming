#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * find_listint_loop - Finds the start node of the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 * Return: Address of the node where the loop starts, or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	/* Move slow by one step and fast by two steps */
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		/* If slow and fast meet, there is a loop */
		if (slow == fast)
		{
			/* Reset slow to the head */
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			/* Now slow and fast point to the node where the loop starts */
			return (slow);
		}
	}

	return (NULL); /* No loop found */
}

