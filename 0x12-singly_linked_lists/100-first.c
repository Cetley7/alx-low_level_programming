#include <stdio.h>

/**
 * pre_main - Function executed by the loader before main.
 *
 * Description: This function is executed automatically by the loader
 * before the main function is executed.
 */
void pre_main(void) __attribute__ ((constructor));

/**
 * pre_main - Function executed by the loader before main.
 */
void pre_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

