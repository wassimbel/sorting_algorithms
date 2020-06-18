#include "sort.h"

/**
 * shell_sort - sorts and array of integers
 * in ascending order using the shell sort algorithm
 * @array: the array
 * @size: the array's size
 * Return: void
 **/

void shell_sort(int *array, size_t size)
{
	size_t h = 0, i = 0, idx = 0;
	int v = 0;

	while (h < size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			idx = i;
			while (idx >= h && array[idx - h] >= array[idx])
			{
				v = array[idx];
				array[idx] = array[idx - h];
				array[idx - h] = v;
				idx -= h;
			}
		}
		print_array(array, size);
		h = h / 3;
	}
}
