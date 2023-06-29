#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to capitalize.
 *
 * Return: Pointer to the capitalized string.
 */
char *cap_string(char *str)
{
    int i = 0;

    /* Capitalize first letter */
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;

    while (str[i] != '\0')
    {
        /* Check for separator characters */
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
            str[i] == ',' || str[i] == ';' || str[i] == '.' ||
            str[i] == '!' || str[i] == '?' || str[i] == '"' ||
            str[i] == '(' || str[i] == ')' || str[i] == '{' ||
            str[i] == '}')
        {
            /* Capitalize next letter */
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                str[i + 1] -= 32;
        }

        i++;
    }

    return (str);
}
