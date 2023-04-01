#include "push_swap.h"

void short_sort_b(t_node **head_a, t_node **head_b)
{
	int	size;	
		
	size = list_size(head_b);
	if (list_size(head_b) == 5)
	{	
		push_a(head_a, head_b);
		push_a(head_a, head_b);
		sort_three_b(head_b);
		if ((*head_a)->value > (*head_a)->next->value)
			swap_a(head_a);
	}
	else if (list_size(head_b) == 4)
	{	
		push_a(head_a, head_b);
		sort_three_b(head_b);
	}
	else if (list_size(head_b) == 3)
		sort_three_b(head_b);
	while (list_size(head_b) != size)
		merge_b(head_a, head_b);
}

