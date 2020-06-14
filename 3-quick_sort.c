#include "sort.h"

void quick_sort(int *array, size_t size)
{
		lomuto(array, size, 0, size - 1);
}

void lomuto(int *array, size_t size, int lo, int hi)
{

	if (lo < hi)
	{
		int part = lomuto_partition(array, size, lo, hi)
		quick_sort(array, size, low, part - 1);
		quick_sort(array, size, part + 1, hi);
	}
}


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
			lo++;
		}
	}
	tmp2 = array[i];
	array[i] = hi;
	hi = tmp2;
	return lo;
}
