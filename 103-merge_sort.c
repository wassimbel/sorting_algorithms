#include "sort.h"
void merge(int *array, size_t size, int begin, int mid, __attribute__((unused))int end, int *array_copy)
{
	int i = begin, j = mid;
	size_t k = 0;

	for (k = 0; k < size; k++)
	{
		if (i < mid && array[i] <= array[j])
		{
			array_copy[k] = array[i];
			i++;
		}
		else
		{
			array_copy[k] = array[j];
			j++;
		}
	}
}

void top_down(int *array, size_t size, int begin, int end, int *array_copy)
{
        int mid = 0;

        if (size == 1)
                return;

        if (size % 2 == 0)
                 mid = (begin + end - 1) / 2;

        else
                mid = (begin + end) / 2;

        top_down(array, size, begin, mid, array_copy);
        top_down(array, size, mid, end, array_copy);
        merge(array, size, begin, mid, end, array_copy);

}


void merge_sort(int *array, size_t size)
{
        int *array_copy = malloc(size * sizeof(int));


        if (array && size)
                top_down(array, size, 0, (int)(size - 1), array_copy);
        free(array_copy);
}

