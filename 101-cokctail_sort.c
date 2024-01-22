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
 * list_len - size of list
 * @list: first node
 * Return: size of list
 */
int list_len(listint_t **list)
{
	listint_t *temp = *list;
	int len = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

void cocktail_sort_list(listint_t **list)
{
	int left = 0;
	int right = list_len(list) - 1;
	int i, j;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;
	printf("%d\n", right);
	while (left <= right)
	{
		for (i = left; i < right && temp->next != NULL; i++)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(temp, temp->next);
				if (temp->next->prev == NULL)
					*list = temp->next;
			}
			temp = temp->next;
		}
		right--;
		temp = temp->prev;
		for (j = right; j > left && temp != NULL; j--)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(temp->prev, temp);
				if (temp->prev == NULL)
					*list = temp;
			}
			temp = temp->prev;
		}
		left++;
		temp = *list;
	}
}
