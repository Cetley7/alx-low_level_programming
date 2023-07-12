#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int count_words(char *str);
int word_length(char *str);
void free_words(char **words);

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: Pointer of strings (words),
 *         or if allocation fails
 */
char **strtow(char *str)
{
	char **words;
	int num_words, idx1, idx2, idx3, length, word_len;

	/* Check for NULL or empty string */
	if (str == NULL || *str == '\0')
		return (NULL);

	/* Count the number of words */
	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	/* Allocate memory */
	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	/* Extract words from the string and store em in the array */
	idx1 = 0;
	idx2 = 0;
	while (str[idx1] != '\0')
	{
		if (str[idx1] != ' ')
		{
			word_len = word_length(&str[idx1]);
			words[idx2] = malloc((word_len + 1) * sizeof(char));
			if (words[idx2] == NULL)
			{
				free_words(words);
				return (NULL);
			}

			length = 0;
			for (idx3 = idx1; idx3 < (idx1 + word_len); idx3++)
			{
				words[idx2][length] = str[idx3];
				length++;
			}
			words[idx2][length] = '\0';

			idx2++;
			idx1 += word_len;
		}
		else
		{
			idx1++;
		}
	}

	words[idx2] = NULL; 

	return (words);
}

/**
 * count_words - counts  number of words in one  string
 * @str: the string
 *
 * Return: Number of words
 */
int count_words(char *str)
{
	int count = 0, idx = 0;

	while (str[idx] != '\0')
	{
		if (str[idx] != ' ' && (str[idx + 1] == ' ' || str[idx + 1] == '\0'))
			count++;
		idx++;
	}

	return (count);
}

/**
 * word_length - computes length
 * @str: the string
 *
 * Return: Length of the word
 */
int word_length(char *str)
{
	int length = 0, idx = 0;

	while (str[idx] != '\0' && str[idx] != ' ')
	{
		length++;
		idx++;
	}

	return (length);
}

/**
 * free_words - frees memory allocated
 * @words:  array of words
 *
 * Return: Nothing
 */
void free_words(char **words)
{
	int idx = 0;

	while (words[idx] != NULL)
	{
		free(words[idx]);
		idx++;
	}

	free(words);
}

