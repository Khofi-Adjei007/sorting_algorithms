#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using the
*               Bubble Sort algorithm.
*
* @array: The array to be sorted.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
size_t f, index;
int tmp;

/* Check if the array is empty or has only one element */
if (size < 2)
return;

/* Outer loop for each pass through the array */
for (f = 0; f < size; f++)
{
/* Inner loop to compare adjacent elements and swap if necessary */
for (index = 0; index < size - 1; index++)
{
/* Compare adjacent elements and swap if necessary */
if (array[index] > array[index + 1])
{
/* Swap the elements */
tmp = array[index];
array[index] = array[index + 1];
array[index + 1] = tmp;

/* Print the current state of the array after swapping */
print_array(array, size);
}
}
}
}
