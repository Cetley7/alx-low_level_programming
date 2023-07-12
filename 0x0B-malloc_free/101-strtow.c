#include <stdlib.h>
#include <string.h>

/**
 * count_words - Count the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
    int count = 0;
    int is_word = 0;

    while (*str)
    {
        if (*str != ' ' && !is_word)
        {
            is_word = 1;
            count++;
        }
        else if (*str == ' ')
        {
            is_word = 0;
        }
        str++;
    }

    return count;
}

/**
 * allocate_memory - Allocate memory for an array of words.
 * @num_words: The number of words.
 *
 * Return: The allocated memory for the words array.
 */
char **allocate_memory(int num_words)
{
    char **words = (char **)malloc(sizeof(char *) * (num_words + 1));
    if (words == NULL)
        return NULL;

    return words;
}

/**
 * free_memory - Free the memory allocated for the words array.
 * @words: The words array.
 * @num_words: The number of words.
 */
void free_memory(char **words, int num_words)
{
    int i;
    for (i = 0; i < num_words; i++)
    {
        free(words[i]);
    }
    free(words);
}

/**
 * strtow - Split a string into an array of words.
 * @str: The input string.
 *
 * Return: The array of words, or NULL on failure.
 */
char **strtow(char *str)
{
    int num_words;
    char **words;
    char *token;
    int i;

    if (str == NULL || *str == '\0')
        return NULL;

    num_words = count_words(str);
    words = allocate_memory(num_words);
    if (words == NULL)
        return NULL;

    token = strtok(str, " ");
    i = 0;
    while (token != NULL)
    {
        words[i] = strdup(token);
        if (words[i] == NULL)
        {
            free_memory(words, i);
            return NULL;
        }
        token = strtok(NULL, " ");
        i++;
    }

    words[i] = NULL;
    return words;
}

