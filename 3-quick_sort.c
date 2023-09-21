#include "sort.h"

/**
 * quick_sort - Function that sorts an array based on
 * quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
		
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function for quick sort
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - Function that sets the pivot for quick_sort
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	
	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_sort(array, size, 0);
		}
	}
	
	swap(&array[i + 1], &array[high]);
	print_sort(array, size, 0);
	
	return i + 1;
}

/**
 * swap - Function that swaps two values
 * @a: First value
 * @b: Second value
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * print_sort - Function that prints as it should
 * @array: Array to be printed
 * @size: Size of array
 * @init: Should initialize array
 */
void print_sort(int *array, size_t size, int init)
{
	if (init)
	{
		print_array(array, size);
	}
}