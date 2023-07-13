#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * find_length - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int find_length(char *str)
{
	int length = 0;

	while (*str++)
		length++;

	return (length);
}

/**
 * create_array - Creates an array of characters and initializes it with 'x'.
 * @size: The size of the array to be initialized.
 *
 * Description: If there is insufficient memory, the function
 *              exits with a status of 98.
 * Return: A pointer to the created array.
 */
char *create_array(int size)
{
	char *array;
	int index;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	for (index = 0; index < size - 1; index++)
		array[index] = 'x';

	array[index] = '\0';

	return (array);
}

/**
 * iterate_zeros - Iterates through a string of numbers with leading zeros.
 * @str: The string of numbers to iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
char *iterate_zeros(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * get_digit - Converts a digit character to an integer.
 * @c: The character to be converted.
 *
 * Description: If c is not a digit, the function exits with a status of 98.
 * Return: The converted integer.
 */
int get_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (digit);
}

/**
 * get_product - Multiplies a string of numbers by a single digit.
 * @product: The buffer to store the result.
 * @multiplicand: The string of numbers to be multiplied.
 * @digit: The single digit multiplier.
 * @zeros: The number of leading zeros required.
 *
 * Description: If the multiplicand contains non-digit characters, the function
 *              exits with a status of 98.
 */
void get_product(char *product, char *multiplicand, int digit, int zeros)
{
	int multiplicand_length, num, tens = 0;

	multiplicand_length = find_length(multiplicand) - 1;
	multiplicand += multiplicand_length;

	while (*product)
	{
		*product = 'x';
		product++;
	}

	product--;

	while (zeros--)
	{
		*product = '0';
		product--;
	}

	for (; multiplicand_length >= 0; multiplicand_length--, multiplicand--, product--)
	{
		if (*multiplicand < '0' || *multiplicand > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*multiplicand - '0') * digit;
		num += tens;
		*product = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*product = (tens % 10) + '0';
}

/**
 * add_numbers - Adds the numbers stored in two strings.
 * @final_product: The buffer storing the running final product.
 * @next_product: The next product to be added.
 * @next_length: The length of next_product.
 */
void add_numbers(char *final_product, char *next_product, int next_length)
{
	int num, tens = 0;

	while (*(final_product + 1))
		final_product++;

	while (*(next_product + 1))
		next_product++;

	for (; *final_product != 'x'; final_product--)
	{
		num = (*final_product - '0') + (*next_product - '0');
		num += tens;
		*final_product = (num % 10) + '0';
		tens = num / 10;

		next_product--;
		next_length--;
	}

	for (; next_length >= 0 && *next_product != 'x'; next_length--)
	{
		num = (*next_product - '0');
		num += tens;
		*final_product = (num % 10) + '0';
		tens = num / 10;

		final_product--;
		next_product--;
	}

	if (tens)
		*final_product = (tens % 10) + '0';
}

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
	char *final_product, *next_product;
	int size, index, digit, zeros = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = iterate_zeros(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeros(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = find_length(argv[1]) + find_length(argv[2]);
	final_product = create_array(size + 1);
	next_product = create_array(size + 1);

	for (index = find_length(argv[2]) - 1; index >= 0; index--)
	{
		digit = get_digit(*(argv[2] + index));
		get_product(next_product, argv[1], digit, zeros++);
		add_numbers(final_product, next_product, size - 1);
	}

	for (index = 0; final_product[index]; index++)
	{
		if (final_product[index] != 'x')
			putchar(final_product[index]);
	}
	putchar('\n');

	free(next_product);
	free(final_product);

	return (0);
}

