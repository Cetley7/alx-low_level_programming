#include "lists.h"
#include <stdlib.h>

/**
 * _str_len - Calculates the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _str_len(const char *s)
{
	int length;

	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: A pointer to the head of the list.
 * @str: The string to be added to the new node.
 * Return: A pointer to the new node, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	int index, string_length;
	char *str_dup;
	list_t *new_element;

	if (str == NULL || head == NULL)
		return (NULL);

	string_length = _str_len(str);
	str_dup = malloc((string_length + 1) * sizeof(char));
	if (str_dup == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		str_dup[index] = str[index];

	new_element = malloc(sizeof(list_t));
	if (new_element == NULL)
	{
		free(str_dup);
		return (NULL);
	}

	new_element->str = str_dup;
	new_element->len = string_length;
	new_element->next = *head;
	*head = new_element;

	return (new_element);
}

