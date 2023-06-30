#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - Prints the content of a buffer
 * @b: The buffer to print
 * @size: The size of the buffer
 */
void print_buffer(char *b, int size)
{
	int a, c;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (a = 0; a < size; a += 10)
	{
		printf("%08x: ", a);

		for (c = 0; c < 10; c++)
		{
			if (a + c < size)
				printf("%02x", b[a + c]);
			else
				printf("  ");

			if (c % 2 != 0)
				printf(" ");
		}

		for (c = 0; c < 10; c++)
		{
			if (a + c >= size)
				break;

			if (isprint(b[a + c]))
				printf("%c", b[a + c]);
			else
				printf(".");
		}

		printf("\n");
	}
}
