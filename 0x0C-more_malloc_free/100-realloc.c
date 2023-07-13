#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory block to reallocate
 * @old_size: Size of the old memory block
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 *         or NULL if new_size is 0 and ptr is not NULL, or if malloc fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	void *new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	unsigned int min_size = (old_size < new_size) ? old_size : new_size;
	memcpy(new_ptr, ptr, min_size);
	free(ptr);

	return (new_ptr);
}

