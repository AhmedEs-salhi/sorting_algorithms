#include "sort.h"

/**
 * swap1 - function that swap two integer numbers
 *
 * @a: the first integer
 * @b: the seconde integer
 */

void swap1(int *a, int *b)
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
	size_t j, k;
	size_t start, end;
	bool sorted;

	start = 0;
	end = size - 1;
	sorted = true;
	while(sorted)
	{
		sorted = false;
		for (j = start; j < end; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap1(&array[j], &array[j + 1]);
				sorted = true;
				print_array(array, size);
			}
		}
		if(!sorted)
			break;

		sorted = false;
		--end;
		for (k = end - 1; k >= start; --k)
		{
			if (array[k] > array[k + 1])
			{
				swap1(&array[k], &array[k + 1]);
				sorted = true;
				print_array(array, size);
			}
		}
		++start;
	}
}
