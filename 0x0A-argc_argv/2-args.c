#include "main.h"
#include <stdio.h>
/**
 * main - Prints all command-line arguments
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		_puts(argv[i]);
		_putchar('\n');
	}

	return (0);
}
