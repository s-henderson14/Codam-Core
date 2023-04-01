#include "push_swap.h"

void	sort_three_b(t_node **head)
{
	t_node	*mid;
	t_node	*last;

	mid = (*head)->next;
	last = last_node(*head);
	if ((*head)->value == largest_number(head) && mid->value < last->value)
	{	
		reverse_rotate_b(head);
		swap_b(head);
	}
	else if (last->value == largest_number(head) && (*head)->value < mid->value)
	{	
		swap_b(head);
		reverse_rotate_b(head);
	}
	else if (mid->value == largest_number(head) && (*head)->value > last->value)
		swap_b(head);
	else if (mid->value == largest_number(head) && (*head)->value < last->value)
		rotate_b(head);
	else if (last->value == largest_number(head) && (*head)->value > mid->value)
		reverse_rotate_b(head);
}

