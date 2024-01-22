#include "sort.h"

/**
 * insertion_sort_list - sorts int in ascending order.
 * @list: double linked int to be sorted.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead,  *new, *temp;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	lead = (*list)->next;
	new = lead->next;
	while (lead)
	{
		if (lead->n < lead->prev->n)
		{
			temp = lead->prev;
			while (temp && (lead->n < temp->n))
			{
				if (!(temp->prev))
				{
					temp->prev = lead;
					lead->prev->next = lead->next;
					if (lead->next)
						lead->next->prev = lead->prev;
					lead->next = temp;
					lead->prev = NULL;
					*list = lead;
				}
				else
				{
					lead->prev->next = lead->next;
					if (lead->next)
						lead->next->prev = lead->prev;
					temp->prev->next = lead;
					lead->prev = temp->prev;
					temp->prev = lead;
					lead->next = temp;
				}
				print_list(*list);
				temp = lead->prev;
			}
		}
		lead = new;
		new = (lead != NULL) ? lead->next : NULL;
	}
}
