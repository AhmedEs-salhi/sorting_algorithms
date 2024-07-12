#include "sort.h"

/**
 * getMax - function that finds the max gap index of an array
 *
 * @size: tha size of the array
 *
 * Return: the max gap index of an arra
 */

size_t getMax(size_t size)
{
	size_t n;

	n = 1;
	while (n < size)
		n = n * 3 + 1;

	return ((n - 1) / 3);
}

/**
 * shell_sort - function that sort an array using the shell algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;

	for (gap = getMax(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
	{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
