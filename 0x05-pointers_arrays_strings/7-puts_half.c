#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @s: Pointer to the string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return (len);
}

/**
 * puts_half - Prints half of a string
 * @str: Pointer to the string
 */
void puts_half(char *str)
{
    int len = _strlen(str);
    int start;

    if (len % 2 == 0)
        start = len / 2;
    else
        start = (len - 1) / 2 + 1;

    while (str[start] != '\0')
    {
        _putchar(str[start]);
        start++;
    }

    _putchar('\n');
}
