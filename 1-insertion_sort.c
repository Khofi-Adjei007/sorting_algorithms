#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
*                       order using the Insertion sort algorithm.
*
* @list: Double pointer to the head of the doubly linked list.
*/

void insertion_sort_list(listint_t **list)
{
listint_t *unsorted;

/* Check if the list is empty or has only one node */
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

unsorted = (*list)->next;
while (unsorted != NULL)
{
listint_t *current = unsorted;
unsorted = unsorted->next;

/* Perform insertion sort to place 'current' node in its correct position */
while (current->prev && current->prev->n > current->n)
{
/* Swap the current node with its previous node in the list */
current = swap_node(current, list);

/* Print the list after the swap */
print_list(*list);
}
}
}

/**
* swap_node - Swaps a node with its previous one in the doubly linked list.
*
* @node: Pointer to the node to be swapped.
* @list: Pointer to the head of the doubly linked list.
*
* Return: Return a pointer to a node which was entered.
*/

listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *back = node->prev, *current = node;

/* Update the next and prev pointers of the nodes surrounding the current node */
back->next = current->next;
if (current->next)
current->next->prev = back;

/* Perform the swap by updating the next and prev pointers of the current node */
current->next = back;
current->prev = back->prev;
back->prev = current;

/* If the current node is now the new head, update the list pointer */
if (current->prev)
current->prev->next = current;
else
*list = current;

/* Return the pointer to the current node after the swap */
return (current);
}
