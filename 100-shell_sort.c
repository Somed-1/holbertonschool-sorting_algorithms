#include "sort.h"

/**
 * shell_sort - sorts array
 * @array: array
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int h = 1;
	int i, j, key;

	if (size == 1 || array == NULL)
		return;

	/* Knuth Sequence */
	while ((size_t)h <= size / 3)
		h = 3 * h + 1;

	while (h > 0)
	{
		for (i = h; (size_t)i < size; i++)
		{
			key = array[i];
			j = i;

			while (j >= h && array[j - h] > key)
			{
				array[j] = array[j - h];
				j -= h;
			}

			array[j] = key;
		}
		print_array(array, size);

		h = (h - 1) / 3;
	}
}
