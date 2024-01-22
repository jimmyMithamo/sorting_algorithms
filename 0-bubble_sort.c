#include <stdio.h>
#include "sort.h"

/**
 *bubble_sort - function to sort an array of integers
 *@array:array to be sorted
 *@size:number of elements in the array
 *Return:nothing
 *
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
