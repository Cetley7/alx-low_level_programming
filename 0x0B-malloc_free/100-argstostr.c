#include <stdlib.h>
#include <string.h>

/**
 * argstostr - Concatenates all arguments of a program.
 * @ac: The argument count.
 * @av: An array of arguments.
 *
 * Return: A pointer to the concatenated string, or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	if (ac == 0 || av == NULL)
		return (NULL);

	int total_length = 0;
	for (int i = 0; i < ac; i++)
		total_length += strlen(av[i]) + 1; /* +1 for '\n' */

	char *result = malloc(sizeof(char) * total_length);
	if (result == NULL)
		return (NULL);

	int current_position = 0;
	for (int i = 0; i < ac; i++)
	{
		strcpy(result + current_position, av[i]);
		current_position += strlen(av[i]);
		result[current_position] = '\n';
		current_position++;
	}

	return (result);
}

