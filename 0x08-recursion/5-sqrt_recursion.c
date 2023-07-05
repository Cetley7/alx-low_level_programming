#include "main.h"

/**
 * calculate_sqrt - Calculates the square root of a number using recursion.
 * @n: The number to find the square root of.
 * @sqrt: The current guess for the square root.
 *
 * Return: The natural square root of n if found, otherwise -1.
 */
int calculate_sqrt(int n, int sqrt)
{
	if (sqrt * sqrt == n) /* Base case: square root found */
		return (sqrt);

	if (sqrt * sqrt > n) /* Base case: square root does not exist */
		return (-1);

	return (calculate_sqrt(n, sqrt + 1)); /* Recursively increment the guess for the square root */
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root of n if found, otherwise -1.
 */
int _sqrt_recursion(int n)
{
	if (n < 0) /* Error case: negative number */
		return (-1);

	return (calculate_sqrt(n, 0));
}
