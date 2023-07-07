#include <stdio.h>
#include "main.h"

/**
 * main - Prints the number of arguments passed into main
 * @argc: Number of command line arguments
 * @argv: Array name
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int z;

	if (argc == 1)
		printf("%d\n", argc - 1);
	else
	{
		for (z = 0; *argv; z++, argv++)
			;

		printf("%d\n", z - 1);
	}

	return (0);
}
