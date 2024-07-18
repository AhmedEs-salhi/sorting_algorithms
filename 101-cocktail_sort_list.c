#include "sort.h"

/**
 * swapNodes - function that swap two nodes
 *
 * @current: the first node
 * @current_old: the seconde node
 * @list: the head of the doubly linked list
 *
 */

void swapNodes(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;

	if (temp1 != NULL)
		temp1->prev = current_old;
	if (temp2 != NULL)
		temp2->next = current;

	current->prev = temp2;
	current_old->next = temp1;
	current->next = current_old;
	current_old->prev = current;

	if (*list == current_old)
		*list = current;
	print_list(*list);
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
	listint_t *start = NULL, *end = NULL, *current = *list;

	if (!list)
		return;
	if (!(*list)->next)
	       return;
	if (!(*list))
		return;

	do {
		while (current->next)
		{
			if (current->n > current->next->n)
				swapNodes(current->next, current, list);
			else
				current = current->next;
		}

		end = current;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
				swapNodes(current, current->prev, list);
			else
				current = current->prev;
		}
		start = current;
	} while (start != end);
}
