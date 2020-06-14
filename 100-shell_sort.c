#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the list to sort
 * Return: void
 **/

void shell_sort(int *array, size_t size)
{
	size_t h = 1, i = 0, idx = 0;
	int v = 0;

	while (h < size / 3)
		h = h * 3 + 1;

	while (h > 0)
	{
		for(i = h; i < size; i++)
		{
			v = array[i];
			idx = i;
			while (idx >= h && array[idx - h] >= v)
				idx -= h;
			array[i] = array[idx];
			array[idx] = v;
		}
		print_array(array, size);
		h = (h - 1) / 3;

	}
}
