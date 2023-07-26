#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
*                       order using the Insertion sort algorithm.
*
* @list: Double pointer to the head of the doubly linked list.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *node;

/* Check if the list is NULL or has only one node */
if (list == NULL || (*list)->next == NULL)
return;

node = (*list)->next;
while (node)
{
while ((node->prev) && (node->prev->n > node->n))
{
node = swap_node(node, list);
/* Print the list after each swap */
print_list(*list);
}

node = node->next;
}
}

/**
* swap_node - Swaps a node with its previous
* one in the doubly linked list.
*
* @node: Pointer to the node to be swapped.
* @list: Pointer to the head of the doubly linked list.
*
* Return: Return a pointer to a node which was entered.
*/
listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *back = node->prev, *current = node;

/*
 * Update the next and prev pointers of the nodes
 * surrounding the current node
 */

back->next = current->next;
if (current->next)
current->next->prev = back;

/*
 * Perform the swap by updating the next and
 * prev pointers of the current nod
 */

current->next = back;
current->prev = back->prev;
back->prev = current;

/* If the current node is now the new head, update the list pointer */
if (current->prev)
current->prev->next = current;
else
*list = current;

return (current);
}
