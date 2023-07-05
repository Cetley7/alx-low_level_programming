#include "main.h"

/**
 * check_palindrome - Helper function to recursively check if a string is a palindrome.
 * @s: The string to check.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if the string is a palindrome, otherwise 0.
 */
int check_palindrome(char *s, int start, int end);

/**
 * get_string_length - Helper function to get the length of a string recursively.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int get_string_length(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + get_string_length(s + 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, otherwise 0.
 */
int is_palindrome(char *s)
{
	int length = get_string_length(s);
	if (length <= 1)
		return (1);

	return (check_palindrome(s, 0, length - 1));
}

/**
 * check_palindrome - Helper function to recursively.
 * @s: The string to check.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if the string is a palindrome, otherwise 0.
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end) /* Base case: string is a palindrome */
		return (1);

	if (s[start] != s[end]) /* Base case: string is not a palindrome */
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}
