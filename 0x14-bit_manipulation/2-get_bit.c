#include "main.h"

/**
 * get_bit - returns bit value.
 * @n: unsigned long int input.
 * @index: index of the bit.
 *
 * Return: value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int u;

	if (n == 0 && index < 64)
		return (0);

	for (u = 0; u <= 63; n >>= 1, u++)
	{
		if (index == u)
		{
			return (n & 1);
		}
	}

	return (-1);
}
