#include "sort.h"
/**
 * swap - function that swaps two nodes in double linked list
 * @list: doubly linked list
 * @first: first node to swap
 * @second: second node to swap
 */
void swap(listint_t **list, listint_t *first, listint_t *second)
{

	if (first == NULL || second == NULL)
		return;
	if (*list == first)
		*list = second;
	if (first->prev != NULL)
		(first->prev)->next = first->next;
	if (second->next != NULL)
		(second->next)->prev = second->prev;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
}
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous, *current, *next;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (current != NULL)
	{
		previous = current->prev;
		next = current->next;
		while (previous != NULL && current->n < previous->n)
		{
			swap(list, previous, current);
			print_list(*list);
			previous = current->prev;
		}
		current = next;
	}
}
