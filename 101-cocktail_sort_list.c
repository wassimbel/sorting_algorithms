#include "sort.h"
/**
 * check - swaps a node to the right
 * @list: pointer to the list to be checked
 * Return: 0 if false or 1 if true
 **/

int check(listint_t *list)
{
	listint_t *next = NULL;

	while (list->next)
	{
		next = list->next;
		if (list->n > next->n)
			return (0);
		list = list->next;
	}
	return (1);

}
/**
 * swap_r - swaps a node to the right
 * @list: pointer to the list to be checked
 * @cur: pointer to the node to be swapped
 * @next: pointer to the to be swapped with
 * Return: void
 **/

void swap_r(listint_t **list, listint_t **cur, listint_t **next)
{
	listint_t *tmp = NULL;

	(*cur)->next = (*next)->next;
	if ((*next)->next)
		(*next)->next->prev = *cur;
	tmp = (*cur)->prev;
	(*cur)->prev = *next;
	(*next)->next = *cur;
	(*next)->prev = tmp;
	if ((*next)->prev)
		(*next)->prev->next = *next;
	if (!tmp)
		*list = *next;
}

/**
 * swap_l - swaps a node to the left
 * @list: pointer to the list to be checked
 * @cur: pointer to the node to be swapped
 * @next: pointer to the to be swapped with
 * Return: void
 **/

void swap_l(listint_t **list, listint_t **cur, listint_t **next)
{
	listint_t *tmp = NULL;

	(*cur)->prev = (*next)->prev;
	if ((*next)->prev)
		(*next)->prev->next = *cur;
	tmp = (*cur)->next;
	(*cur)->next = *next;
	(*next)->prev = *cur;
	(*next)->next = tmp;
	if ((*next)->next)
		(*next)->next->prev = *next;
	if (!(*cur)->prev)
		*list = *cur;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail sort algorithm
 * @list: pointer to the list to sort
 * Return: void
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *next = NULL, *prev = NULL;
	int flag = 0, nc = 0;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (tmp)
	{
		flag = 0;
		next = tmp->next;
		prev = tmp->prev;
		if (next && tmp->n > next->n)
		{
			swap_r(list, &tmp, &next);
			print_list(*list);
			flag = 1;
		}
		else if (prev && tmp->n < prev->n)
		{
			swap_l(list, &tmp, &prev);
			print_list(*list);
			flag = 1;
		}
		if (!tmp->prev)
			nc = 0;
		if (check(*list) == 1)
			break;
		else if (!tmp->next)
		{
			tmp = tmp->prev;
			nc = -1;
		}
		else if (nc == -1 && flag == 0)
			tmp = tmp->prev;
		else if (tmp->next && flag == 0)
			tmp = tmp->next;
	}
}
