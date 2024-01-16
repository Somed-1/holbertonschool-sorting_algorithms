#include "sort.h"


/**
 * insertion_sort_list - sorts array
 * @list: double linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = *list, *iter_back = cur, *temp, *tnext;

	while (cur != NULL)
	{
		while (iter_back->prev != NULL && (iter_back->n < iter_back->prev->n))
		{
			if (iter_back->next != NULL)
				iter_back->next->prev = iter_back->prev;
			if (iter_back->prev->prev != NULL)
				iter_back->prev->prev->next = iter_back;

			temp = iter_back->prev;
			iter_back->prev = temp->prev;
			tnext = iter_back->next;
			iter_back->next = temp;
			temp->next = tnext;
			temp->prev = iter_back;

			if (iter_back->prev == NULL)
				*list = iter_back;

			print_list(*list);
		}
		cur = cur->next;
		iter_back = cur;
	}
}
