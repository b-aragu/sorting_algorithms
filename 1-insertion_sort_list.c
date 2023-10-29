#include "sort.h"

/**
 * len_list - find the length of the list
 * @head: the head of the list
 * Return: the length of the list
 */
int len_list(listint_t *head)
{
	int len = 0;

	while(head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

/**
 * insertion_sort_list - implement insertion sort
 * @list: doubly linked list to perform sorting on
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next;

	if (list == NULL || *list == NULL || len_list(*list) < 2)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		next = curr->next;
		prev = curr->prev;

		while (prev != NULL && (prev->n) > (curr->n))
		{
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
			prev = curr->prev;
		}
		curr = next;
	}
}
