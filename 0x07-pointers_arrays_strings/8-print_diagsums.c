#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the diagonals of a square matrix
 * @a: Pointer to the matrix array
 * @size: Size of the matrix (number of rows or columns)
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0; /* Sum of the main diagonal */
	int sum2 = 0; /* Sum of the secondary diagonal */

	/* Calculate the sum of the main diagonal */
	for (i = 0; i < size; i++)
		sum1 += a[(size + 1) * i];

	/* Calculate the sum of the secondary diagonal */
	for (i = 0; i < size; i++)
		sum2 += a[(size - 1) * (i + 1)];

	printf("%d, %d\n", sum1, sum2);
}
