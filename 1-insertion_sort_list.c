#include "sort.h"

/**
 *
 *
 *
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t
	index = tmp->next;

	if (*list == NULL || *list->next = NULL)
		return;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		while (index)
		{
			index = index->next;
			if (tmp->n > index->n)
			{
				tmp->next = index->next;
				index->next = tmp;
				tmp->prev = index;
				
