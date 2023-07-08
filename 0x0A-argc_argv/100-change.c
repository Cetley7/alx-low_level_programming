#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	int minimum_coins = calculate_minimum_coins(cents);
	printf("%d\n", minimum_coins);

	return (0);
}

/**
 * calculate_minimum_coins - Calculates the minimum number of coins required
 *                           to make change for a given amount of money.
 * @cents: The amount in cents.
 *
 * Return: The minimum number of coins.
 */
int calculate_minimum_coins(int cents)
{
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = sizeof(coins) / sizeof(coins[0]);
	int count = 0;

	for (int i = 0; i < num_coins; i++)
	{
		count += cents / coins[i];
		cents %= coins[i];
	}

	return (count);
}
