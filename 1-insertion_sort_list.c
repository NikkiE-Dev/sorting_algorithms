#include "sort.h"

/**
 * swapping - had to seperate code
 *
 * @frstnode: first node used in function
 * @secnode: second node used in function
 */

void swapping(listint_t *frstnode, listint_t *secnode)
{
	secnode->prev = frstnode->prev;

	if (secnode->prev)
	secnode->prev->next = secnode;
	frstnode->prev = secnode;
	frstnode->next = secnode->next;

	if (frstnode->next)
	frstnode->next->prev = frstnode;
	secnode->next = frstnode;
}

/**
 * insertion_sort_list - sorting algorithm used on doubly linked list
 *
 * @list: the list created
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *fllw;

	if (list == NULL)
	{
		return;
	}

	curr = *list;
	temp = curr->next;

	while (temp)
	{
		if (curr->n > temp->n)
		{
			swapping(curr, temp);
			if (!temp->prev)
			*list = temp;
			print_list(*list);
			fllw = temp->prev;

			while (fllw && fllw->n > temp->n)
			{
				swapping(fllw, temp);
				if (!temp->prev)
				*list = temp;
				print_list(*list);
				fllw = temp->prev;
			}
		}

		else
		curr = temp;
		temp = curr->next;
	}
}
