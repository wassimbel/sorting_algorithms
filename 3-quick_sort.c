#include "sort.h"


/**
 * lomuto_partition - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @lo: lower
 * @hi: higher
 * Return: lo
 */

int lomuto_partition(int *array, size_t size, int lo, int hi)
{

	int pivot = array[hi];
	int tmp = 0, tmp2 = 0, i = lo;


	for (i = lo; i < hi; i++)
	{
		if (array[i] <= pivot)
		{
			tmp = array[i];
			array[i] = array[lo];
			array[lo] = tmp;
			if (lo != i)
				print_array(array, size);
			lo++;
		}
	}
	tmp2 = array[lo];
	array[lo] = pivot;
	array[hi] = tmp2;
	if (lo != hi)
		print_array(array, size);
	return (lo);
}

/**
 * lomuto - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @lo: lower
 * @hi: higher
 * Return: void
 */

void lomuto(int *array, size_t size, int lo, int hi)
{

	if (lo < hi)
	{
		int part = lomuto_partition(array, size, lo, hi);

		lomuto(array, size, part, hi);
		lomuto(array, size, lo, part - 1);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */


void quick_sort(int *array, size_t size)
{
	lomuto(array, size, 0, (int)(size - 1));
}
