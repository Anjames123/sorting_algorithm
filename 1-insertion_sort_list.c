#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                         order using the Insertion sort algorithm
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	while (curr != NULL)
	{
		listint_t *prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			/* Swap nodes */
			listint_t *tmp = prev->prev;

			prev->prev = curr;
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->prev = tmp;
			curr->next = prev;

			if (tmp != NULL)
				tmp->next = curr;
			else
				*list = curr;

			prev = curr->prev;

			/* Print list after each swap */
			print_list(*list);
		}

		curr = curr->next;
	}
}
