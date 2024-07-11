#include "sort.h"
#include <stdio.h>

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

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		swap(&array[min], &array[i]);
		print_array(array, size);
	}
}
