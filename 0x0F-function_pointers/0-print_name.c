#include "function_pointers.h"
#include <stdlib.h>
/**
 * print_name - Prints a name.
 * @name: The name to be printed.
 * @f: Pointer to a function that will be used to print the name.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

