#include "sort.h"

/**
 *
 *
 *
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *index, *current;
	index = tmp->next;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		while (index)
		{
			index = index->next;
			if (tmp->n > index->n)
			{
				current = index->next;
				index->prev = tmp->prev;
				index->next = tmp;
				tmp->prev = index;
				tmp->next = current;
				print_list(*list);
			}
		}
	}
}
