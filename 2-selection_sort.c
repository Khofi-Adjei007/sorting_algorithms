#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order
*                  using the Selection sort algorithm.
*
* @array: The array to be sorted.
* @size: The size of the array.
*/

void selection_sort(int *array, size_t size)
{
size_t i, index;
int tmp, swap, flag;

if (array == NULL || size < 2)
return;

for (i = 0; i < size; i++)
{
tmp = i;
flag = 0;

/*
 * Find the index of the minimum element in
 * the unsorted part of the array
 */

for (index = i + 1; index < size; index++)
{
if (array[tmp] > array[index])
{
tmp = index;
flag = 1; /* Set flag to 1 if a swap is needed */
}
}

/*
 * Swap the found minimum element with the
 * first element of the unsorted part
 */

if (flag)
{
swap = array[i];
array[i] = array[tmp];
array[tmp] = swap;

/* Print the array after each swap */
print_array(array, size);
}
}
}
