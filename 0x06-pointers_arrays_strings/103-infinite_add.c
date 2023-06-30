#include "main.h"

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0, sum = 0;
	int i, j;

	/* Calculate the lengths of the input strings */
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	if (len1 > size_r || len2 > size_r)
		return (0);

	/* Add digits from right to left */
	for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--)
	{
		sum = carry;

		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		carry = sum / 10;
		sum %= 10;

		/* Store the result in reverse order */
		r[size_r - 1] = sum + '0';
		size_r--;
	}

	if (size_r == 0 && carry)
		return (0);

	/* Shift the result to the right if necessary */
	if (size_r > 0 && carry)
	{
		for (i = size_r - 1; i >= 0; i--)
			r[i + 1] = r[i];

		r[0] = carry + '0';
	}

	return (&r[size_r]);
}
