#include "sort.h"
#include <stdio.h>

/**
 * len_list - find the length of the list.
 *
 * @h: the list.
 * Return: length of the list.
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sortsa doubly linked list of integers in
 *             ascending order using the insertion sort algorithm
 *
 * @list: Pointer to pointer to the head node of the doubky linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		swap = current;

		while (swap->prev != NULL && swap->n < swap->prev->n)
		{
			swap->prev->next = swap->next;
			if (swap->next != NULL)
				swap->next->prev = swap->prev;
			swap->next = swap->prev;
			swap->prev = swap->prev->prev;
			swap->next->prev = swap;

			if (swap->prev == NULL)
				*list = swap;

			print_list(*list);



		}

		current = current->next;
	}

}
