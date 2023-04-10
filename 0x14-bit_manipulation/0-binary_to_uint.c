#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ui;
	int height, base_two;

	if (!b)
		return (0);

	ui = 0;

	for (height  = 0; b[height] != '\0'; height++)
		;

	for (height--, base_two = 1; height >= 0; height--, base_two *= 2)
	{
		if (b[height] != '0' && b[height] != '1')
		{
			return (0);
		}

		if (b[height] & 1)
		{
			ui += base_two;
		}
	}

	return (ui);
}
