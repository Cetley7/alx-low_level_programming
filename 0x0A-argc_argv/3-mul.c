#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 1 if not enough arguments passed in, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc == 1 || argc == 2)
	{
		printf("Error\n");
		return 1;
	}
	else
	{
		result = 1;

		for (num1 = 1; num1 < 3; num1++)
			result *= atoi(argv[num1]);

		printf("%d\n", result);
	}

	return 0;
}
