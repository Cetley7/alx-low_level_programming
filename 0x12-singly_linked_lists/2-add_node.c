#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of the list.
 * @head: Pointer to a pointer to the first node of the list.
 * @str: The string to be duplicated and stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
    if (str == NULL)
        return (NULL);

    /* Create a new node and allocate memory for it */
    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    /* Duplicate the given string using strdup */
    new_node->str = strdup(str);
    if (new_node->str == NULL) {
        free(new_node);
        return (NULL);
    }

    /* Update the new node's next pointer to the current head */
    new_node->next = *head;

    /* Update the head to point to the new node */
    *head = new_node;

    return (new_node);
}

