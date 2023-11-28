#include "sort.h"
/**
 * swap - function that swaps two integers
 * @x: first int to swap
 * @y: second int to swap
 */
void swap(int *x, int *y)
{
	int aux = *x;

	*x = *y;
	*y = aux;
}
/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (size < 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
