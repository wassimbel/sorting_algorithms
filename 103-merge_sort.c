#include "sort.h"

/**
 * merge - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * @mid: middle element
 * @begin: start element
 * @end: end element
 * @ar_cp: a copy of the array
 * Return: void
 */
void merge(int *array, size_t size, int begin, int mid, int end, int *ar_cp)
{
	int i = begin, j = mid;
	size_t k = 0;

	(void)end;
	for (k = 0; k < size - 1; k++)
	{
		if (i < mid && j <= (int)size)
		{
			if (array[i] < array[j])
			{
				ar_cp[k] = array[i];
				i++;
			}
			else
			{
				ar_cp[k] = array[j];
				j++;
			}
		}
	}
}

/**
 * top_down - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * @begin: start element
 * @end: end element
 * @array_copy: a copy of the array
 * Return: void
 */

void top_down(int *array, size_t size, int begin, int end, int *array_copy)
{
	int mid = 0;

	if (size == 1)
		return;

	mid = (begin + end - 1) / 2;

	top_down(array, size, begin, mid, array_copy);
	top_down(array, size, mid, end, array_copy);
	merge(array, size, begin, mid, end, array_copy);

}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *array_copy = malloc(size * sizeof(int));
	size_t i = 0;

	if (array && size)
		top_down(array, size, 0, (int)(size - 1), array_copy);
	for (i = 0; i < size; i++)
	{
		array_copy[i] = array[i];
	}
	free(array_copy);
}
