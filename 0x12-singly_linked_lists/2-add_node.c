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
    char *content;
    list_t *new_node;

    if (str == NULL || head == NULL)
        return (NULL);

    string_length = _str_len(str);
    content = malloc((string_length + 1) * sizeof(char));
    if (content == NULL)
        return (NULL);

    for (index = 0; str[index]; index++)
        content[index] = str[index];

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        free(content);
        return (NULL);
    }

    new_node->str = content;
    new_node->len = string_length;
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}

