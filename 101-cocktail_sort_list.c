#include "sort.h"

/**
 * swap_nodes - swaps nodes
 * @first: first node
 * @second: second node
 * Return: void
 */
void swap_nodes(listint_t *first, listint_t *second)
{
	listint_t *f_prev;
	listint_t *s_next;

	if (first == NULL || second == NULL)
		return;

	f_prev = first->prev;
	s_next = second->next;

	if (f_prev != NULL)
		f_prev->next = second;
	if (s_next != NULL)
		s_next->prev = first;

	first->prev = second;
	first->next = s_next;

	second->prev = f_prev;
	second->next = first;
}

/**
 * last_elem - last_elem
 * *first: first node
 * Return: last elem
 */
listint_t *last_elem(listint_t *first)
{
	while (first->next != NULL)
		first = first->next;
	return (first);
}

void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right;
	listint_t *cur;
	int swaped = 0;

	if (list == NULL || *list == NULL)
		return;

	left = *list;
	right = last_elem(*list);

	while (left != right && right->next != left && swaped == 0)
	{
		swaped = 1;
		cur = left;
		while (cur != right)
		{
			if (cur->next == NULL)
				break;
			if (cur->n > cur->next->n)
			{
				swap_nodes(cur, cur->next);
				swaped = 0;
				print_list(*list);
			}
			else
			{
				cur = cur->next;
			}
		}
		if (swaped == 1)
			break;
		right = cur;
		swaped = 1;
		while (cur!= left)
		{
			if (cur->prev == NULL)
				break;
			if (cur->n < cur->prev->n)
			{
				swap_nodes(cur->prev, cur);
				swaped = 0;
				if (cur->prev == NULL)
					*list = cur;
				print_list(*list);
			}
			else
			{
				cur = cur->prev;
			}
		}
		if (swaped == 1)
		{
			break;
		}
		left = cur;
	}
}
