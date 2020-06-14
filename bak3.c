#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */


void quick_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, idx = 0;
	int pv = 0;

	if (!array || !size)
		return;
	for (j = 0; j < size; j++)
	{
		i = j;
		pv = array[j];
		while (i < size)
		{
			if (array[i] < pv)
			{
				idx = i;
				pv = array[i];
			}
			i++;
		}
		if (j != idx && j != size - 1)
		{
			array[idx] = array[j];
			array[j] = pv;
			print_array(array, size);

		}
	}
}
