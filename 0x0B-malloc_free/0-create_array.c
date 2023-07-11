#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  * create_array - creates an array of chars and initializes it.
 *   * @size: the size of the array
 *    * @c: the char to initialize the array with
 *     *
 *      * Return: a pointer to the array, or NULL if it fails
 *       */
char *create_array(unsigned int size, char c)
{
		char *array;
			unsigned int i;

				if (size == 0)
							return (NULL);

					array = malloc(sizeof(char) * (size + 1)); /* Add 1 for the null */
						if (array == NULL)
									return (NULL);

							for (i = 0; i < size; i++)
										array[i] = c;

								array[size] = '\0'; /* Add the null terminator at the end */

									return (array);
}
