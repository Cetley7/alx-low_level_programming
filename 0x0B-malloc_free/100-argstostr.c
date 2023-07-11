#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int total_length = 0, arg_length, i, j;
	int index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		arg_length = 0;
		while (av[i][arg_length] != '\0')
			arg_length++;
		total_length += arg_length + 1; /* Add 1 for newline character */
	}

	concatenated = malloc(sizeof(char) * (total_length + 1));
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		arg_length = 0;
		while (av[i][arg_length] != '\0')
		{
			concatenated[index] = av[i][arg_length];
			index++;
			arg_length++;
		}
		concatenated[index] = '\n';
		index++;
	}

	concatenated[index] = '\0'; /* Add the null terminator */

	return (concatenated);
}

