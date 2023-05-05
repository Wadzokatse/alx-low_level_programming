#include "main.h"

/**
 * flip_bits 
 * @n: number one.
 * @m: number two.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int alxbits;

	for (alxbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			alxbits++;
	}

	return (alxbits);
}
