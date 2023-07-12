#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _argstostr - Concatenates all the arguments of a program.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * Return: A pointer to the concatenated string, or NULL if it fails.
 */
char *_argstostr(int ac, char **av)
{
	if (ac == 0 || av == NULL)
		return (NULL);

	int total_length = 0;
	int i, j;
	char *result;

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			total_length++;
			j++;
		}
		total_length++; /* +1 for the newline character */
	}

	result = (char *)malloc((total_length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	int index = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			result[index] = av[i][j];
			index++;
			j++;
		}
		result[index] = '\n'; /* Add newline character */
		index++;
	}

	result[index] = '\0'; /* Null-terminate the result string */

	return (result);
}
