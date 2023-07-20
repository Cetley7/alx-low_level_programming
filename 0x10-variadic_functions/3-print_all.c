#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the given format.
 * @format: The format string containing the types of arguments.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *ptr = format;
	char *separator = "";
	char *str;

	va_start(args, format);

	while (format && *ptr)
	{
		switch (*ptr)
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", separator, str);
				break;
			default:
				/* Ignore other characters in the format string */
				break;
		}

		separator = ", ";
		ptr++;
	}

	printf("\n");
	va_end(args);
}

