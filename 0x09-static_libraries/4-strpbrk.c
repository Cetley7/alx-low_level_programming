#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to be searched
 * @accept: The string containing the characters to search for
 *
 * Return: The pointer to the byte in s that matches one of the bytes in accept,
 *         or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		char *temp = accept;
		while (*temp)
		{
			if (*temp == *s)
				return (s);
			temp++;
		}
		s++;
	}
	return (NULL);
}
