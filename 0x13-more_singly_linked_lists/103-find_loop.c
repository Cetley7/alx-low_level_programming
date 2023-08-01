#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * find_listint_loop - Find the loop in a linked list using Floyd's algorithm.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    if (head == NULL || head->next == NULL)
        return (NULL);

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

