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
 * Lomutopartition - function lumuto partion
 * @array: array
 * @low: low index
 * @high: high index
 * @size: array size
 * Return: pivot
 */
int Lomutopartition(int array[], size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	i = low - 1;
	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * recursivequickSort - recursive function for quicksort
 * @array: array
 * @low: low index
 * @high: high index
 * @size: array size
 */
void recursivequickSort(int array[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = Lomutopartition(array, low, high, size);
		recursivequickSort(array, low, pi - 1, size);
		recursivequickSort(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 1)
		return;
	recursivequickSort(array, 0, size - 1, size);
}
