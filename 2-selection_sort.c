#include "sort.h"
#include <stdio.h>

/**
 * swapp - function that swap two integer numbers
 *
 * @a: the first number
 * @b: the seconde number
 *
 */

void swapp(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - function that sort an array using the selection sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[i] > array[min])
		{
			swapp(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
