#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum value in an array
 *
 * @array: Pointer to the array to search
 * @size: Size of the array
 *
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * count_sort - Sorts an array of integers using the count sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 * @exp: The exponent of the current digit being sorted
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output, *count, i;
	size_t j;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	count = calloc(10, sizeof(int));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	print_array(array, size);

	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers using the LSD radix sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}
