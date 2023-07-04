#include <stdlib.h>
#include "main.h"

/**
 * _strpbrk - Searches a string
 * @s: Pointer to the string to be searched
 * @accept: Pointer to the string containing the byte
 *
 * Return: Pointer to the byte,
 */
char *_strpbrk(char *s, char *accept)
{
	char *s_ptr;
	char *a_ptr;

	for (s_ptr = s; *s_ptr != '\0'; s_ptr++)
	{
		for (a_ptr = accept; *a_ptr != '\0'; a_ptr++)
		{
			if (*s_ptr == *a_ptr)
				return (s_ptr);
		}
	}

	return (NULL);
}
