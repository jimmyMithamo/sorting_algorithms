#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: numbers of elements in array
 * Return: nothing
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, m_index;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		m_index  = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m_index])
				m_index = j;
		}
		if (m_index != i)
		{
			temp = array[i];
			array[i] = array[m_index];
			array[m_index] = temp;
		}
		print_array(array, size);

	}
}
