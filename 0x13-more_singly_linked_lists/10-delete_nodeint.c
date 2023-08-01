#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index index of a listint_t.
 * @head: Pointer to the pointer of the head node.
 * @index: Index of the node to be deleted (starting from 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* If the node to be deleted is the head node */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;

	/* Traverse the list to find the node before the deletion point */
	while (current != NULL && count < index - 1)
	{
		current = current->next;
		count++;
	}

	/* If the index is out of range or the node after the current is NULL */
	if (current == NULL || current->next == NULL)
		return (-1);

	/* Delete the node at the given index */
	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}

