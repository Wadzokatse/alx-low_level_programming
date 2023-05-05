#include "main.h"
/**
 * binary_to_uint 
 * @b: const char
 * Return: 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int acc = 0;
	int base = 1, q = 0;

	if (b == NULL)
		return (0);

	while (b[q + 1])
	{
		if (b[q] != '0' && b[q] != '1')
			return (0);
		q++;
	}

	while (q >= 0)
	{
		acc += ((b[q] - '0') * base);
		base *= 2;
		q--;
	}


	return (acc);

}
