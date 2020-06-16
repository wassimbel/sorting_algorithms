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

	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			v = array[i];
			idx = i - h;
			while (idx >= h && array[idx] >= v)
				idx -= h;
			if (array[i] < array[idx])
			{
			array[i] = array[idx];
			array[idx] = v;
			}
			if (i != idx)
				print_array(array, size);
		}
/*		print_array(array, size);
 */ printf("//////\n");
		h = (h - 1) / 3;
	}
}
