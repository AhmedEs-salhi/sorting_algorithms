#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * arrayMax - function that define the maximum element of an array
 *
 * @array: the array
 * @size: the size of the array
 *
 * Return: the maximum element of the array
 *
 */

int arrayMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - function that sort an array using the counting algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */

void counting_sort(int *array, size_t size)
{
	int *arr1, *arr2, max;
	size_t i;

	if (size < 2 || !array)
		return;

	max = arrayMax(array, size);
	arr1 = malloc(sizeof(size_t) * (max + 1));
	arr2 = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= max; i++)
		arr1[i] = 0;

	for (i = 0; i < size; i++)
		arr1[array[i]] += 1;

	for (i = 1; (int)i <= max; i++)
		arr1[i] += arr1[i - 1];
	print_array(arr1, max + 1);

	for (i = 0; i < size; i++)
	{
		arr2[arr1[array[i]] - 1] = array[i];
		arr1[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = arr2[i];

	free(arr1);
	free(arr2);
}
