#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: Pointer to the result (r), or 0 if result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0;
    int i, j, k;
    int sum = 0, carry = 0;

    /* Calculate lengths of n1 and n2 */
    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    if (len1 >= size_r || len2 >= size_r)
        return (0); /* Result cannot be stored in r */

    i = len1 - 1;
    j = len2 - 1;
    k = size_r - 1;
    r[k] = '\0'; /* Set null terminator */

    while (i >= 0 || j >= 0)
    {
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';

        carry = sum / 10;
        r[--k] = sum % 10 + '0';

        i--;
        j--;

        if (k == 0 && (i >= 0 || j >= 0 || carry != 0))
            return (0); /* Result cannot be stored in r */
    }

    if (carry != 0 && k > 0)
    {
        r[--k] = carry + '0';
        return (&r[k]);
    }

    return (&r[k + 1]);
}

