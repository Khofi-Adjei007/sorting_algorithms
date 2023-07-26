#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order using the
*              Shell sort algorithm with the Knuth sequence.
*
* @array: The array to be sorted.
* @size: The size of the array.
*/

void shell_sort(int *array, size_t size)
{
int gap, i, j, tmp;

/* Check if the array is NULL or has less than 2 elements */
if (array == NULL || size < 2)
return;

/* Calculate the initial gap using Knuth's sequence */
gap = 1;
while (gap < (int)size / 3)
gap = gap * 3 + 1;

/* Perform Shell sort with Knuth's sequence */
while (gap >= 1)
{
for (i = gap; i < (int)size; i++)
{
tmp = array[i];
j = i;

/* Insertion sort within the gap */
while (j >= gap && array[j - gap] > tmp)
{
array[j] = array[j - gap];
j -= gap;
}

array[j] = tmp;
}

/* Reduce the gap as per Knuth's sequence */
gap = (gap - 1) / 3;

/* Print the array after each reduction of the gap */
print_array(array, size);
}
}
