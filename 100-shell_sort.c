#include "sort.h"

/**
 * shell_sort -sorts elements in an array
 * use knuth's interval(3^n -1)/2
 * @array: an array to be sorted
 * @size: number of elements  in the array
 * Return: Nothing
 *
 */

void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, interval = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	for (; interval > 0; interval = (interval - 1) / 3)
	{
		for (i = interval; i < size; i++)
		{
			aux = array[i];
			for (j = i; j >= interval && array[j - interval] > aux;
					j -= interval)
			{
				if (array[j] != array[j - interval])
					array[j] = array[j - interval];
			}
			if (array[j] != aux)
				array[j] = aux;

		}
		print_array(array, size);
	}
}
