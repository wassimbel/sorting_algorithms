#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the list to sort
 * Return: void
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *index = NULL, *current = NULL, *head = NULL;
	int flag = 0;

	if (*list == NULL || (*list)->next == NULL)
		return;
	(void)head;
	head = *list;

	while (tmp->next)
	{
		flag = 0;
		index = tmp->next;
		if (tmp->n > index->n)
		{
			tmp->next = index->next;
			if (index->next)
			index->next->prev = tmp;
			current = tmp->prev;
			tmp->prev = index;
			index->next = tmp;
			index->prev = current;
			if (index->prev)
				index->prev->next = index;
			if (!current)
			{
				head = index;
				*list = head;
			}
			print_list(*list);
			flag = 1;
		}
		tmp = tmp->next;
		if (flag == 1)
			tmp = head;
	}
}
