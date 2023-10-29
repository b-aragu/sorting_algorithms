#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the collection of integers passed
 * @size: the number of integers in the array
 *
 * Return: nothing(void)
 */
void bubble_sort(int *array, size_t size)
{
	size_t o, m, flag = 0;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (o = 0; o < (size - 1); o++)
	{
		flag = 0;
		for (m = 0; m < (size - 1 - o); m++)
		{
			if (array[m] > array[m + 1])
			{
				temp = array[m];
				array[m] = array[m + 1];
				array[m + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}

}
