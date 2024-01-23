#include "sort.h"
#include <stdlib.h>

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
	size_t i, j;
	size_t temp, increment;

	for (increment = size/2; increment < size; increment/=2)
	{
		for (i = increment; i < size; i++)
		{
			temp = array[1];
			for (j = i; j >= increment; j -= increment)
			{
				if ((int)temp < array[j - increment])
				{
					array[j] = array[j - increment];
				}
				else
				{
					break;
				}
			}
			array[j] = temp;
		}
	}

}
