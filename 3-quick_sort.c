#include "sort.h"

/**
 * recursion - sorts an array of integers recursively
 * @array: array to sort
 * @left: left position
 * @right: right position
 * @size: size
 */
void recursion(int *array, int left, int right, size_t size)
{
	int pivot = 0;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		recursion(array, left, pivot - 1, size);
		recursion(array, pivot + 1, right, size);
	}
}

/**
 * partition - lotumo partition scheme
 * @array: array to sort
 * @left: left position
 * @right: right position
 * @size: array size
 * Return: pivot
 */
int partition(int *array, int left, int right, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[right];
	i = left;

	for (j = left; j < right; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[right];
	array[right] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}

/**
 * quick_sort -  sorts an array of integers using
 * the Quick-sort algorithm in ascending order
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, size - 1, size);
}
