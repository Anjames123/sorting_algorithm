#include "sort.h"

/**
 * merge - Merges two subarrays of an array
 *
 *  @array: Pointer to the array
 *  @size: Size of the array
 *  @left: Pointer to the left subarray
 *  @left_size: Size of the left subarray
 *  @right: Pointer to the right subarray
 *  @right_size: Size of the right subarray
 *
 *  Return: Void
 */
void merge(int *array, size_t size, int *left, size_t left_size,
	       int *right, size_t right_size)
{
	int i, j, k;
	int *merged = malloc(size * sizeof(int));

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	i = 0;
	j = 0;
	k = 0;
	while (i < (int)left_size && j < (int)right_size)
	{
		if (left[i] <= right[j])
		{
			merged[k] = left[i];
			i++;
		}
		else
		{
			merged[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < (int)left_size)
	{
		merged[k] = left[i], i++, k++;
	}
	while (j < (int)right_size)
	{
		merged[k] = right[j], j++, k++;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = merged[i];
	}
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *               the Merge sort algorithm
 *
 *               @array: Pointer to the array
 *               @size: Size of the array
 *
 *               Return: Void
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		int *right = array + mid;
		size_t left_size = mid;
		size_t right_size = size - mid;

		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, size, left, left_size, right, right_size);
	}
}
