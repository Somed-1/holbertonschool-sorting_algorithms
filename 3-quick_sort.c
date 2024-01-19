#include "sort.h"


/**
 * swap - swaps two elements
 * @first: first element
 * @second: second element
 * Return: void
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * lomuto - lomuto
 * @array: array
 * @low: low index
 * @high: pivot
 * Return: int
 */
int lomuto(int *array, int low, int high, int size)
{
	int cur, left = low;

	for(cur = low; cur < high; cur++)
	{
		if (array[cur] <= array[high])
		{
			swap(&array[left], &array[cur]);
			if (left != cur)
				print_array(array, size);
			left++;
		}
	}
	swap(&array[left], &array[high]);
	if (left != cur)
		print_array(array, size);
	return (left);
}

/**
 * recusrion_quick_sort - main func for quick_sort
 * @array: array
 * @low: low index
 * @high: pivot
 * Return: void
 */
void recusrion_quick_sort(int *array, int low,int high, size_t size)
{
	int new_low;

	if (low <= high)
	{
		new_low = lomuto(array, low, high, size);
		recusrion_quick_sort(array, low, new_low - 1, size);
		recusrion_quick_sort(array, new_low + 1, high, size);
	}
}

/**
 * quick_sort - sorts array
 * @array: array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	recusrion_quick_sort(array, 0, size - 1, size);
}
