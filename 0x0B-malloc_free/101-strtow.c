#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    // Count the number of words
    int word_count = 0;
    int len = strlen(str);
    int i = 0;
    while (i < len) {
        // Skip leading spaces
        while (i < len && str[i] == ' ') {
            i++;
        }

        // Count the word
        if (i < len && str[i] != ' ') {
            word_count++;
            while (i < len && str[i] != ' ') {
                i++;
            }
        }
    }

    // Allocate memory for the array of words
    char **words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    // Split the string into words
    int word_index = 0;
    i = 0;
    while (i < len) {
        // Skip leading spaces
        while (i < len && str[i] == ' ') {
            i++;
        }

        // Process the word
        if (i < len && str[i] != ' ') {
            int word_length = 0;
            while (i < len && str[i] != ' ') {
                word_length++;
                i++;
            }

            // Allocate memory for the word
            words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_index] == NULL) {
                // Free memory for already allocated words
                for (int j = 0; j < word_index; j++) {
                    free(words[j]);
                }
                free(words);
                return NULL;
            }

            // Copy the word into the array
            strncpy(words[word_index], str + i - word_length, word_length);
            words[word_index][word_length] = '\0';
            word_index++;
        }
    }

    words[word_index] = NULL;  // Mark the end of the array

    return words;
}

int main() {
    char str[] = "Hello world! This is a test.";
    char **words = strtow(str);

    if (words != NULL) {
        // Print the words
        for (int i = 0; words[i] != NULL; i++) {
            printf("%s\n", words[i]);
        }

        // Free the memory allocated for words
        for (int i = 0; words[i] != NULL; i++) {
            free(words[i]);
        }
        free(words);
    }

    return 0;
}

