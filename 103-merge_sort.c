#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merge two subarrays of arr[]
 * @array: Pointer to the array to be sorted
 * @temp: Pointer to temporary array
 * @left: Starting index of left subarray
 * @mid: Middle index of the subarray
 * @right: Ending index of right subarray
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;

	for (i = left, j = mid + 1, k = left; i <= mid && j <= right; k++)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		} else
		{
			temp[k] = array[j];
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (i = left; i <= right; i++)
	{
		array[i] = temp[i];
	}
}

/**
 * merge_sort_helper - Helper function to sort an array of integers
 * using the Merge Sort algorithm
 * @array: Pointer to the array to be sorted
 * @temp: Pointer to temporary array
 * @left: Starting index of the subarray
 * @right: Ending index of the subarray
 */
void merge_sort_helper(int *array, int *temp, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		merge_sort_helper(array, temp, left, mid);
		merge_sort_helper(array, temp, mid + 1, right);

		printf("Merging...\n");
		printf("[left]: ");
		print_array(&array[left], mid - left + 1);
		printf("[right]: ");
		print_array(&array[mid + 1], right - mid);
		merge(array, temp, left, mid, right);
		printf("[Done]: ");
		print_array(&array[left], right - left + 1);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);

	if (temp == NULL)
	{
		return;
	}

	merge_sort_helper(array, temp, 0, size - 1);

	free(temp);
}
