#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	unsigned int s1_length = 0, s2_length = 0, concat_length = 0;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate the lengths of the strings */
	while (s1[s1_length] != '\0')
		s1_length++;
	while (s2[s2_length] != '\0')
		s2_length++;

	concat_length = s1_length + s2_length;

	/* Allocate memory for the concatenated string */
	concatenated = malloc(sizeof(char) * (concat_length + 1));
	if (concatenated == NULL)
		return (NULL);

	/* Copy s1 to the concatenated string */
	for (i = 0; i < s1_length; i++)
		concatenated[i] = s1[i];

	/* Copy s2 to the concatenated string */
	for (j = 0; j < s2_length; j++)
		concatenated[i + j] = s2[j];

	concatenated[concat_length] = '\0'; /* Add the null terminator */

	return (concatenated);
}

