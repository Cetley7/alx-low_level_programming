#include "main.h"

/**
 * rot13 - Encoding
 * @str: Pointer to the string
 *
 * Return: Return pointer to the modified string
 */
char *rot13(char *str)
{
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int a, b;

	for (a = 0; str[a]; a++)
	{
		for (b = 0; alpha[b]; b++)
		{
			if (str[a] == alpha[b])
			{
				str[a] = rot13[b];
				break;
			}
		}
	}

	return (str);
}
