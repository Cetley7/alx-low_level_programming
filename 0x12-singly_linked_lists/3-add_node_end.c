#include "lists.h"
#include <stdlib.h>
#include <string.h>

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
 * add_node_end - Adds a new node at the end of a linked list.
 * @head: A pointer to the head of the list.
 * @str: The string to be added to the new node.
 * Return: A pointer to the new node, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    int string_length;
    char *str_dup;
    list_t *new_node, *temp;

    if (str == NULL || head == NULL)
        return (NULL);

    string_length = _str_len(str);
    str_dup = strdup(str);
    if (str_dup == NULL)
        return (NULL);

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        free(str_dup);
        return (NULL);
    }

    new_node->str = str_dup;
    new_node->len = string_length;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;

    return (new_node);
}

