#include <stdio.h>
#include "dog.h"
#include <stdlib.h>

/**
 * print_dog - Prints the content of a struct dog
 * @d: Pointer to the struct dog variable to print
 *
 * Description: This function prints the attributes of a dog
 *              stored in the struct dog variable.
 */
void print_dog(struct dog *d)
{
    if (d != NULL)
    {
        printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
        printf("Age: %.1f\n", d->age);
        printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
    }
}

