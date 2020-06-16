#include "sort.h"
/**
 * check - swaps a node to the right
 * @list: pointer to the list to be checked
 * @z: check direction 1 for right and 2 for left
 * Return: 0 if false or 1 if true
 **/

int check(listint_t *list, int z)
{
	listint_t *next = NULL;

	while (list->next)
	{
		if (z == 1)
			next = list->next;
		if (z == 2)
			next = list->prev;
		if (list->n > next->n && z == 1)
			return (0);
		if (list->n < next->n && z == 2)
			return (0);
		if (z == 1)
			list = list->next;
		if (z == 2)
			list = list->prev;
	}
	return (1);

}
/**
 * swap_r - swaps a node to the right
 * @cur: pointer to the node to be swapped
 * @next: pointer to the to be swapped with
 * Return: void
 **/

void swap_r(listint_t **list, listint_t *cur, listint_t *next)
{
	listint_t *tmp = NULL;

	cur->next = next->next;
	if (next->next)
		next->next->prev = cur;
	tmp = tmp->prev;
	cur->prev = next;
	next->next = cur;
	next->prev = tmp;
	if (next->prev)
		next->prev->next = next;
	if (!tmp)
		*list = next;
}

/**
 * swap_l - swaps a node to the left
 * @cur: pointer to the node to be swapped
 * @next: pointer to the to be swapped with
 * Return: void
 **/

void swap_r(listint_t **list, listint_t *cur, listint_t *next)
{
        listint_t *tmp = NULL;

        cur->prev = next->prev;
        if (next->prev)
                next->prev->next = cur;
        tmp = cur->next;
        cur->next = next;
        next->prev = cur;
        next->next = tmp;
        if (next->next)
                next->next->prev = next;
        if (!cur->prev)
                *list = cur;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail sort algorithm
 * @list: pointer to the list to sort
 * Return: void
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *next = NULL, *current = NULL;
	int flag = 0, left = 0, right = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (tmp)
	{
		flag = 0;
		if (right == 1)
			next = tmp->next;
		if (left == 1)
			next = tmp->prev;
		if (tmp->n > next->n && right == 1)
		{
			swap_r(list, tmp, next);
			print_list(*list);
			flag = 1;
		}
		if (tmp->n > next->n && left == 1)
		{
			swap_l(list, tmp, next);
			print_list(*list);
			flag = 1;
		}
		if (!tmp->prev && !check(*list, 2))
			right = 1;
		if (!tmp->next && !check(*list, 1))
			left = 1;
		if (tmp->n > tmp->next->n && right == 1)
			tmp = tmp->next;
		if (tmp->n > tmp->prev->n && left == 1)
			tmp = tmp->prev;

	}
}
