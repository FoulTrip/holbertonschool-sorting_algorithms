#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion
 *                       sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *copyPrev, *copy;

	if (!*list || !list)
		return;

	current = *list;

	while ((current = current->next))
	{
		copy = current;

		while (copy->prev && copy->n < copy->prev->n)
		{
			copyPrev = copy->prev;
			if (copy->next)
				copy->next->prev = copyPrev;
			if (copyPrev->prev)
				copyPrev->prev->next = copy;
			else
				*list = copy;

			copyPrev->next = copy->next;
			copy->prev = copyPrev->prev;
			copy->next = copyPrev;
			copyPrev->prev = copy;

			print_list(*list);
		}
	}
}
