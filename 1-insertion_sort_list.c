#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
*                       order using the Insertion sort algorithm.
*
* @list: Double pointer to the head of the doubly linked list.
*/

void insertion_sort_list(listint_t **list)
{
listint_t *sorted, *unsorted, *current, *next_node;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

sorted = *list;
unsorted = sorted->next;
sorted->next = NULL;
unsorted->prev = NULL;

while (unsorted != NULL)
{
current = unsorted;
unsorted = unsorted->next;

while (sorted != NULL && sorted->n < current->n)
sorted = sorted->next;

if (sorted == NULL)
{
/* Current node is the largest so far */
current->prev = current->next = NULL;
sorted = current;
}
else if (sorted->prev == NULL)
{
/* Current node is the smallest so far */
current->next = sorted;
current->prev = NULL;
sorted->prev = current;
*list = current;
}
else
{

/* Insert current node into its correct position */

next_node = sorted->prev;
current->next = sorted;
current->prev = next_node;
sorted->prev = current;
next_node->next = current;
}

print_list(*list);
}
}
