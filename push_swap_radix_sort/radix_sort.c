#include "push_swap.h"

void	radix_sort(t_node **head_a, t_node **head_b)
{
	int	size;
	int	i;
	int	bit_shift;
	
	size = list_size(head_a);
	rank_stack(head_a);
	bit_shift = 0;
	while (!is_a_sorted(head_a))
	{	
		i = 0;
		while (i < size)
		{	
			if (((*head_a)->rank >> bit_shift) & 1)
				rotate_a(head_a);
			else 
				push_b(head_a, head_b);
			i++;
		}
		while (list_size(head_b) > 0)
			push_a(head_a, head_b);
		bit_shift++;
	}
	
}
