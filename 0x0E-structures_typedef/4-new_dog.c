#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Pointer to a string containing the dog's name
 * @age: Age of the dog
 * @owner: Pointer to a string containing the dog owner's name
 *
 * Return: Pointer to the created dog (dog_t), or NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    char *name_copy, *owner_copy;
    int name_len, owner_len;

    /* Calculate the lengths of name and owner */
    name_len = strlen(name);
    owner_len = strlen(owner);

    /* Allocate memory for the new dog structure */
    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    /* Allocate memory for the copies of name and owner */
    name_copy = malloc((name_len + 1) * sizeof(char));
    owner_copy = malloc((owner_len + 1) * sizeof(char));

    if (name_copy == NULL || owner_copy == NULL)
    {
        free(new_dog);
        free(name_copy);
        free(owner_copy);
        return (NULL);
    }

    /* Copy name and owner to the allocated memory */
    strcpy(name_copy, name);
    strcpy(owner_copy, owner);

    /* Set the new dog's attributes */
    new_dog->name = name_copy;
    new_dog->age = age;
    new_dog->owner = owner_copy;

    return (new_dog);
}
