#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length, i;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	length = 0;
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicate string */
	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	/* Copy the original string to the duplicate */
	for (i = 0; i < length; i++)
		duplicate[i] = str[i];

	duplicate[length] = '\0'; /* Add the null terminator */

	return (duplicate);
}

