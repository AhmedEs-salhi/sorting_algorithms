#include "sort.h"

/**
 * swip - function permute two numbers
 *
 * @a: the address of the first number
 * @b: the address of the seconde number
 */

void swip(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - function that sort an array of integers
 *		using to bubble sort
 *
 * @array: the address of the array to sort
 * @size: the size of the @array variable
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swip(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
