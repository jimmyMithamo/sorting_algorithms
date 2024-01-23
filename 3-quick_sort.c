#include "sort.h"

/**
 * swaps - Swaps the ints in array.
 * @i: Pointer to the first int.
 * @j: Pointer to the second int.
 * Return: void.
 */
void swaps(int *i, int *j)
{
	int temp = *i;

	*i = *j;
	*j = temp;
}

/**
 * lomuto_partition - Perform Lomuto partition on an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * @below: Starting index of the partition.
 * @above: Ending index of the partition.
 *
 * Return: Final int.
 */
int lomuto_partition(int *array, size_t size, int below, int above)
{
	int *pivot = array + above;
	int a = below - 1;
	int b;

	for (b = below; b < above; b++)
	{
		if (array[b] < *pivot)
		{
			if (++a != b)
			{
				swaps(array + a, array + b);
				print_array(array, size);
			}
		}
	}

	if (array[++a] > *pivot)
	{
		swaps(array + a, pivot);
		print_array(array, size);
	}

	return (a);
}

/**
 * lomuto_sorting - Implement quicksort.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 * Return: void.
 */
void lomuto_sorting(int *array, size_t size, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, size, low, high);
		lomuto_sorting(array, size, low, partition - 1);
		lomuto_sorting(array, size, partition + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size >= 2)
    lomuto_sorting(array, size, 0, size - 1);
}
