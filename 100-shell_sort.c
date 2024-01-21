#include "sort.h"

/**
 * shell_sort - sorts array
 * @array: array
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size) {
	int h = 1;
	int i, j, key;

	/* Knuth Sequence */
	while (h <= size / 3)
		h = 3 * h + 1;

	while (h > 0) 
	{
		for (int i = h; i < size; i++)
		{
			key = array[i];
			j = i;
			print("Index: %d, Key: %d, Checked: ", i, key);

			while (j >= h && array[j - h] > key)
			{
				printf("j:%d, el: %d", j, array[j]);
				array[j] = array[j - h];
				j -= h;
			}

			array[j] = key;
		}
		print_array(array, size);

		h = (h - 1) / 3;
	}
}
