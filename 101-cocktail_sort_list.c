#include "sort.h"

/**
 * swap - swap two adjacent nodes in a doubly linked list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 * @list: pointer to the list
 * Return: void
 */
void swap(listint_t *node1, listint_t *node2, listint_t **list)
{
	/* connect node1's previous node to node2 */
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	node2->prev = node1->prev;

	/* connect node2's next node to node1 */
	node1->prev = node2;
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->next = node1;
	/* print the current state of the list */
	print_list(*list);
}

/**
 * cocktail_sort_list - sort a doubly linked list
 * using the Cocktail Shaker algorithm
 * @list: pointer to the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *node;

	if (list == NULL || *list == NULL)
		return;

	start = *list;
	end = NULL;

	while (swapped == 1)
	{
		swapped = 0;

		for (node = start; node != end; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swap(node, node->next, list);
				swapped = 1;
			}
		}

		end = node->prev;

		if (swapped == 0)
			break;

		swapped = 0;

		for (node = end; node != start; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap(node->prev, node, list);
				swapped = 1;
			}
		}

		start = node->next;
	}
}
