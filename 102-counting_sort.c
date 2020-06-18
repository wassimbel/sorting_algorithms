#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *out = NULL, *count = NULL, i = 0, max = 0;

	if (!array && size < 2)
		return;
	while (array[i])
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	out = malloc(sizeof(int) * size);
	if (!out)
		return;
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(out);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; array[i]; i++)
		++count[array[i]];
	for (i = 0; i < max + 1; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; array[i]; i++)
	{
		out[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}
	for (i = 0; array[i]; i++)
		array[i] = out[i];
	free(count);
	free(out);
}
