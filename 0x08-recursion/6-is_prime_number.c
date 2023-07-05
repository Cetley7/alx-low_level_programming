#include "main.h"

/**
 * is_divisible - Checks if a number is divisible by any number less than it.
 * @n: The number to check.
 * @divisor: The current divisor to check.
 *
 * Return: 1 if the number is divisible by any number less than it.
 */
int is_divisible(int n, int divisor)
{
	if (divisor == 1) /* Base case: divisor reaches 1, number is prime */
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_divisible(n, divisor - 1));
}

/**
 * is_prime_number - Checks if a number is a prime number.
 * @n: The number to check.
 *
 * Return: 1 if the number is prime, otherwise 0.
 */
int is_prime_number(int n)
{
	if (n <= 1) /* Base case: numbers less than or equal to 1 are not prime */
		return (0);

	return (is_divisible(n, n - 1));
}
