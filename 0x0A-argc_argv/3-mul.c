#include <stdio.h>
#include "main.h"

/**
 * custom_atoi - converts a string to an integer
 * @str: string to be converted
 *
 * Return: the integer converted from the string
 */
int custom_atoi(char *str)
{
	int i, sign, num, len, found, digit;

	i = 0;
	sign = 0;
	num = 0;
	len = 0;
	found = 0;
	digit = 0;

	while (str[len] != '\0')
		len++;

	while (i < len && found == 0)
	{
		if (str[i] == '-')
			++sign;

		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (sign % 2)
				digit = -digit;
			num = num * 10 + digit;
			found = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			found = 0;
		}
		i++;
	}

	if (found == 0)
		return (0);

	return (num);
}

/**
 * main - multiplies two numbers
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int result, operand1, operand2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	operand1 = custom_atoi(argv[1]);
	operand2 = custom_atoi(argv[2]);
	result = operand1 * operand2;

	printf("%d\n", result);

	return (0);
}

