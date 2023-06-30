#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
	char *ptr = str;
	int i, j;
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (; *ptr != '\0'; ptr++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (*ptr == input[i])
			{
				*ptr = output[i];
				break;
			}
		}
	}
	return (str);
}
