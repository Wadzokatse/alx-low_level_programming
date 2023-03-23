#include "function_pointers.h"
#include <stdlib.h>

/**
 * int_index - searches for an integer
 * @array: integer array
 * @size: size of array (number of integers)
 * @cmp: function pointer
 * Return: void
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int a, result;

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	for (a = 0; a < size; a++)
	{
		result = cmp(array[a]);
		if (result == 1)
			return (a);
	}
	return (-1);
}
