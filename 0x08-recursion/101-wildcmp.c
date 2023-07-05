#include "main.h"

/**
 * wildcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0') /* Base case: s2 ends with '*' */
			return (1);

		if (*s1 == '\0') /* Base case: s1 reaches the end */
			return (0);

		if (*(s2 + 1) == '*') /* Ignore consecutive '*' characters in s2 */
			return (wildcmp(s1, s2 + 1));

		if (*s1 == *(s2 + 1)) /* Recursive case: check if remaining strings match */
			return (wildcmp(s1 + 1, s2 + 2) || wildcmp(s1 + 1, s2));

		return (wildcmp(s1 + 1, s2)); /* Recursive case: skip a character in s1 */
	}

	if (*s1 == *s2) /* Recursive case: current characters match */
	{
		if (*s1 == '\0') /* Base case: both strings reach the end */
			return (1);

		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0); /* Base case: characters do not match */
}
