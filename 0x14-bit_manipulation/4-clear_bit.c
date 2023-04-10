#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * Return: integer (1 success, -1 error)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int sock;

	if (index >= (sizeof(*n) * 8))
		return (-1);
	sock = 1;
	sock = sock << index;
	sockk = ~sock;
	*n = *n & sock;

	return (1);
}
