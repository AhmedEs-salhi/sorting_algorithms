#include "sort.h"

/**
 * swapping - function that swap two integer variables
 *
 * @array: the array where the variables exist
 * @size: the size of the array variable
 * @a: the address of the first number to swap
 * @b: the address of the seconde number to swap
 *
 */

void swapping(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * lomuto - function that do the lomuto partition scheme
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * @low: the low index of the array
 * @high: the high index of the array
 *
 * Return: the index of the pivot
 */

size_t lomuto(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot;

	pivot = array[high];
	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swapping(array, size, &array[j], &array[i++]);
	swapping(array, size, &array[i], &array[high]);

	return (i);
}

/**
 * quickSort - function that sort an array using the quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * @low: low index of the array
 * @high: high index of the array
 *
 */

void quickSort(int *array, size_t size, ssize_t low, ssize_t high)
{
	size_t p;

	if (low < high)
	{
		p = lomuto(array, size, low, high);
		quickSort(array, size, low, p - 1);
		quickSort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - function that sort an array using the quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quickSort(array, size, 0, size - 1);
}
