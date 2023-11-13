#include "main.h"

/**
 * _strncpy - Copies at most n bytes of the string pointed to by src,
 *            including the terminating null byte ('\0'), to the buffer
 *            pointed to by dest.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of bytes to be copied.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		*ptr = src[i];
		ptr++;
	}

	for (; i < n; i++)
	{
		*ptr = '\0';
		ptr++;
	}

	return (dest);
}
