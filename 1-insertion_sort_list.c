#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    node1->next = node2->next;
    if (node2->next != NULL)
        node2->next->prev = node1;
    node2->prev = node1->prev;
    node2->next = node1;
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;
    node1->prev = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    if (list == NULL || *list == NULL)
        return;

    for (current = (*list)->next; current != NULL; current = insert)
    {
        insert = current->next;
        while (current->prev != NULL && current->prev->n > current->n)
        {
            swap_nodes(list, current->prev, current);
            print_list((const listint_t *)*list);
        }
    }
}
