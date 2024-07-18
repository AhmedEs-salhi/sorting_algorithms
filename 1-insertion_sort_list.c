#include "sort.h"

/**
 * swap_nodes - function that swap two nodes
 *
 * @current: the first node
 * @current_old: the seconde node
 * @list: the head of the doubly linked list
 *
 */

void swap_nodes(listint_t *current, listint_t *current_old, listint_t **list)
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
}

/**
 * insertion_sort_list - function that use the insertion sort
 *			to sort a doubly linked list
 *
 * @list: the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_nodes(j->prev, j, list);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}

