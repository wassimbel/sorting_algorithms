#include "sort.h"

/**
 *
 *
 *
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *index, *current, *next;
	index = tmp->next;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (tmp)
	{
		index = tmp->next;
		while (tmp->n > index->n)
		{
				current = tmp->prev;
				next = index->next;
				tmp->next = next;
				tmp->prev = index;
				index->next = tmp;
				index->prev = current;
				print_list(*list);
			index = index->next;
		}
		tmp = tmp->next;
	}
}
