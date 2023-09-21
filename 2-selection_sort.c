#include "sort.h"

/**
 * selection_sort - sort an array using a selection sort algorithm
 * @array: pointer to an array
 * @size: sie of the array
*/
void selection_sort(int *array, size_t size)
{
	int iterator, tmp, minValue;
	size_t i, minPosition;

	iterator = tmp = minValue = 0;

	if (!array || size == 0)
		return;

	while (iterator < (int) size - 1)
	{
		tmp = minValue = array[iterator];
		for (i = iterator; i < size; i++)
		{
			if (array[i] < minValue)
			{
				minValue = array[i];
				minPosition = i;
			}
		}

		if (minValue < array[iterator])
		{
			array[iterator] = minValue;
			array[iterator] = tmp;
			print_array(array, size);
		}

		iterator++;
	}
	
}