#include "sort.h"

/**
<<<<<<< HEAD
 * bubble_sort - Sorts an array of integers in ascending order using the
 *                Bubble sort algorithm.
 *                @array: The array of integers to be sorted.
 *                @size: The size of the array to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp;

	if (size < 2)
=======
 * swap_ints - Swaps the positions of two elements in an array.
 * @a: The first element to be swapped.
 * @b: The second element to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
>>>>>>> e5c5956b8a9afd06ba27f340deafcb1630c21684
		return;

	while (bubbly == false)
	{
<<<<<<< HEAD
		for (j = 0; j < size - 1 - i; j++)
=======
		bubbly = true;
		for (i = 0; i < len - 1; i++)
>>>>>>> e5c5956b8a9afd06ba27f340deafcb1630c21684
		{
			if (array[i] > array[i + 1])
			{
<<<<<<< HEAD
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
=======
				swap_ints(array + i, array + i + 1);
>>>>>>> e5c5956b8a9afd06ba27f340deafcb1630c21684
				print_array(array, size);
				bubbly = false;
			}
		}
<<<<<<< HEAD
=======
		len--;
>>>>>>> e5c5956b8a9afd06ba27f340deafcb1630c21684
	}
}
