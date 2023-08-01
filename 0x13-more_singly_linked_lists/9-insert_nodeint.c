#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * create_new_node - Creates a new node and initializes it with the given value.
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
static listint_t *create_new_node(int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	if (new_node != NULL)
	{
		new_node->n = n;
		new_node->next = NULL;
	}
	return (new_node);
}

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to the pointer of the head node.
 * @idx: Index of the list where the new node should be added (starting from 0).
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	/* If the new node is to be inserted at the beginning */
	if (idx == 0)
	{
		new_node = create_new_node(n);
		if (new_node == NULL)
			return (NULL);

		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;

	/* Traverse the list to find the node before the insertion point */
	while (current != NULL && count < idx - 1)
	{
		current = current->next;
		count++;
	}

	/* If idx is out of range, return NULL */
	if (current == NULL)
		return (NULL);

	new_node = create_new_node(n);
	if (new_node == NULL)
		return (NULL);

	/* Insert the new node between the current node and the next node */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

