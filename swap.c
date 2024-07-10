#include "sort.h"

/**
 * swap - function premute two integer numbers
 *
 * @a: the address of the first number
 * @b: the address of the seconde number
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
