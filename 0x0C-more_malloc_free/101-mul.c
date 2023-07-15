#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_input(int argc, char *argv[]);
char *multiply_numbers(char *num1, char *num2);
char *remove_leading_zeros(char *str);
char *multiply_single_digit(char *num, char digit, int zeros);
char *add_numbers(char *num1, char *num2);

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Description: If the number of arguments is incorrect or either number
 *              contains non-digit characters, the program exits with a
 *              status of 98.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *result;

	if (validate_input(argc, argv) != 0)
	{
		printf("Error\n");
		exit(98);
	}

	if (strcmp(argv[1], "0") == 0 || strcmp(argv[2], "0") == 0)
	{
		printf("0\n");
		return (0);
	}

	result = multiply_numbers(argv[1], argv[2]);

	printf("%s\n", result);

	free(result);

	return (0);
}

/**
 * validate_input - Validates the command-line arguments.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 if the input is valid, otherwise -1.
 */
int validate_input(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
		return (-1);

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				return (-1);
		}
	}

	return (0);
}

/**
 * multiply_numbers - Multiplies two positive numbers.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: A pointer to the resulting product.
 */
char *multiply_numbers(char *num1, char *num2)
{
	int len1, len2, zeros = 0, i;
	char *result, *temp, *product;

	len1 = strlen(num1);
	len2 = strlen(num2);
	result = calloc(len1 + len2 + 1, sizeof(char));

	if (result == NULL)
		exit(98);

	for (i = len2 - 1; i >= 0; i--)
	{
		temp = multiply_single_digit(num1, num2[i], zeros++);
		product = add_numbers(result, temp);
		free(result);
		free(temp);
		result = product;
	}

	return (result);
}

/**
 * remove_leading_zeros - Removes leading zeros from a string.
 * @str: The string to process.
 *
 * Return: A pointer to the processed string.
 */
char *remove_leading_zeros(char *str)
{
	while (*str == '0' && *(str + 1) != '\0')
		str++;

	return (str);
}

/**
 * multiply_single_digit - Multiplies a number by a single digit.
 * @num: The number.
 * @digit: The single digit.
 * @zeros: The number of zeros to append.
 *
 * Return: A pointer to the resulting product.
 */
char *multiply_single_digit(char *num, char digit, int zeros)
{
	int len, i, carry = 0;
	char *result;

	len = strlen(num);
	result = calloc(len + 2 + zeros, sizeof(char));

	if (result == NULL)
		exit(98);

	for (i = len - 1; i >= 0; i--)
	{
		int product = (num[i] - '0') * (digit - '0') + carry;
		result[i + 1] = (product % 10) + '0';
		carry = product / 10;
	}

	if (carry)
		result[0] = carry + '0';

	for (i = 0; i < zeros; i++)
		result[len + 1 + i] = '0';

	return (remove_leading_zeros(result));
}

/**
 * add_numbers - Adds two numbers.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: A pointer to the resulting sum.
 */
char *add_numbers(char *num1, char *num2)
{
	int len1, len2, carry = 0, i;
	int max_len = len1 > len2 ? len1 : len2;
	char *result;

	len1 = strlen(num1);
	len2 = strlen(num2);
	result = calloc(max_len + 2, sizeof(char));

	if (result == NULL)
		exit(98);

	for (i = 0; i <= max_len; i++)
	{
		int sum = (i < len1 ? (num1[len1 - 1 - i] - '0') : 0) +
				  (i < len2 ? (num2[len2 - 1 - i] - '0') : 0) + carry;

		result[max_len + 1 - i] = (sum % 10) + '0';
		carry = sum / 10;
	}

	if (carry)
		result[0] = carry + '0';

	return (remove_leading_zeros(result));
}

