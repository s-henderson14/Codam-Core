#include "push_swap.h"

void	quick_sort(t_node **head_a, t_node **head_b, int elements)
{
	int	stack_size;
	int	pivot;	
	
	stack_size = elements;
	pivot = pivot_finder(head_a)->value;
	if (is_a_sorted(head_a))
		exit(0);
	elements = first_split(head_a,head_b, elements, pivot);
	quick_sort(head_a, head_b, stack_size - elements);



	

