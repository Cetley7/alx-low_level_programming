#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: The number of arguments.
 * @argv: Array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* Print the opcodes of the main function */
	unsigned char *address = (unsigned char *)&main;
	for (i = 0; i < bytes; i++)
	{
		printf("%02x", address[i]);
		if (i < bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}

