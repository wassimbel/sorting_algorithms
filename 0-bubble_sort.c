#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	for (i = 0; i < size - 1; i++)
	{
		size_t flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

