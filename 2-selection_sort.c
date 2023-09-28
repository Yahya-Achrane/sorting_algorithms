#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 * Description: Sorts the array in-place in ascending order using
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, indx = 0, temp = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		indx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[indx])
				indx = j;
		}
 		if (indx != i)
		{
			temp = array[i];
			array[i] = array[indx];
			array[indx] = temp;
			print_array(array, size);
		}
	}
}
