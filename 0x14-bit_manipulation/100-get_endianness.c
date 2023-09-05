#include "main.h"

/**
 * get_endianness - Checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int test = 1;
	char *byte = (char *)&test;

	/* If the least significant byte is at the lowest address, it's little endian */
	if (*byte)
		return 1; /* Little endian */
	else
		return 0; /* Big endian */
}

