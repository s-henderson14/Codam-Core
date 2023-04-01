#include "push_swap.h"

void	merge_b(t_node **head_a, t_node **head_b)
{
	t_node *last;
	t_node *mid;

	last = last_node(*head_b);
	mid = (*head_b)->next;
	if ((*head_a)->value < (*head_b)->value && (*head_a)->value > mid->value)
	{
		push_b(head_a, head_b);
		swap_b(head_b);
	}
	else if ((*head_a)->value < mid->value && (*head_a)->value > last->value)
	{	
		reverse_rotate_b(head_b);
		push_b(head_a, head_b);
		rotate_b(head_b);
		rotate_b(head_b);
	}
	else if ((*head_a)->value > (*head_b)->value)
		push_b(head_a, head_b);
	else if ((*head_a)->value < last->value)
	{
		push_b(head_a, head_b);
		rotate_b(head_b);
	}
}

