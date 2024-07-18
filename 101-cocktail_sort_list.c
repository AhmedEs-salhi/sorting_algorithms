#include "sort.h"

/**
 * swapNodes - function that swap two nodes
 *
 * @a: the first node
 * @b: the seconde node
 *
 */

void swapNodes(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

}

/**
 * cocktail_sort_list - function that sort a doubly linked list
 *			using the cocktail sort algorithm
 *
 * @list: the head of the doubly linked list to be sorted
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	bool swapped;

	start = (*list);
	end = NULL;

	do {
		current = start;
		swapped = false;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swapNodes(current, current->next);
				swapped = true;
				print_list((const listint_t *)*list);
			}
			current = current->next;
		}

		if (!swapped)
			break;

		end = current;
		current = current->prev;

		while (current != start)
		{
			if (current->n < current->prev->n)
			{
				swapNodes(current, current->prev);
				swapped = true;
				print_list((const listint_t *)*list);
			}
			current = current->prev;
		}
		start = current;
	} while (swapped);
}
