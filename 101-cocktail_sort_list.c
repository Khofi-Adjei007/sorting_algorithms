#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list.
*
* @list: Double pointer to the head of the doubly linked list.
* @node1: First node to swap.
* @node2: Second node to swap.
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev)
node1->prev->next = node2;
if (node2->next)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;

node1->prev = node2;
node2->next = node1;

if (node1->next == NULL)
*list = node1;
}

/**
* forward_pass - Performs the forward pass of Cocktail shaker sort.
*
* @list: Double pointer to the head of the doubly linked list.
* @swapped: Pointer to an integer to indicate if a swap occurred.
*/
void forward_pass(listint_t **list, int *swapped)
{
listint_t *current = *list;

while (current->next != NULL)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
*swapped = 1;
}
else
current = current->next;
}
}

/**
* backward_pass - Performs the backward pass of Cocktail shaker sort.
*
* @list: Double pointer to the head of the doubly linked list.
* @swapped: Pointer to an integer to indicate if a swap occurred.
*/
void backward_pass(listint_t **list, int *swapped)
{
listint_t *current = *list;

while (current->prev != NULL)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
*swapped = 1;
}
else
current = current->prev;
}
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
*                      order using the Cocktail shaker sort algorithm.
*
* @list: Double pointer to the head of the doubly linked list.
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;

if (list == NULL || *list == NULL)
return;

do {
swapped = 0;

/* Forward pass (Bubble sort phase) */
forward_pass(list, &swapped);

/* If no elements were swapped, the list is sorted */
if (swapped == 0)
break;

swapped = 0;

/* Backward pass (Bubble sort phase in reverse) */
backward_pass(list, &swapped);
} while (swapped);
}
