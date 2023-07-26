#include "sort.h"

/* Function prototypes */
void quick_sort_recursive(int *array, int low, int high);
int lomuto_partition(int *array, int low, int high);

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick sort algorithm with Lomuto partition.
*
* @array: The array to be sorted.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1);
}

/**
* quick_sort_recursive - Recursive helper function for Quick sort.
*
* @array: The array to be sorted.
* @low: The starting index of the partition.
* @high: The ending index of the partition.
*/
void quick_sort_recursive(int *array, int low, int high)
{
if (low < high)
{
int pivot_idx = lomuto_partition(array, low, high);
quick_sort_recursive(array, low, pivot_idx - 1);
quick_sort_recursive(array, pivot_idx + 1, high);
}
}

/**
* lomuto_partition - Performs Lomuto partition on the array.
*
* @array: The array to be sorted.
* @low: The starting index of the partition.
* @high: The ending index of the partition.
*
* Return: The index of the pivot element after partitioning.
*/
int lomuto_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1, j, temp;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, high + 1);
}
}
}

if (i + 1 != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, high + 1);
}

return i + 1;
}
