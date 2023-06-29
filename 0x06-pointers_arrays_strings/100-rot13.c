#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 encryption.
 * @str: The string to be encoded.
 *
 * Return: Pointer to the encoded string.
 */
char *rot13(char *str)
{
	char *ptr = str;
	int i;

	while (*ptr != '\0')
	{
		i = 0;

		while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
				str[i] += 13;
			else
				str[i] -= 13;

			i++;
		}

		ptr++;
	}

	return (str);
}
