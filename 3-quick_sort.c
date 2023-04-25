#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers in ascending order
 *          using quick sort algorithm.
 *
 * @array: array of integers to sort.
 * @size: size of the array to sort.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_helper(array, 0, size - 1, size);
}

/**
 * quicksort_helper - helper function for quick_sort that sorts an array
 * using lumoto_partition scheme and recursively calls to quick_sort helper.
 * @array: array to sort.
 * @low: the lowest index of the partition.
 * @high: the highest index of the partition.
 * @size: size of the array.
 *
 * Return: void
 */

void quicksort_helper(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quicksort_helper(array, low, pivot_index - 1, size);
		quicksort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - finds the partition index of an array
 *         using the lomuto partition scheme.
 * @array: the array of integers to partition.
 * @low: the lowest index of the partition.
 * @high: the highest index of the partition.
 * @size: size of the array.
 *
 * Return: index of the pivot element.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;
	int temp = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
