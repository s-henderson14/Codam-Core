#include "push_swap.h"

void	sorter(t_node **head_a, t_node **head_b)
{
	t_node	*pivot;
	int		size;

	size = list_size(head_a);
	if (is_sorted(head_a))
			exit(0);
	while (!is_sorted(head_a))
	{
		pivot = last_node(*head_a);
		while (pivot != *head_a)
		{
			if ((*head_a)->value < pivot->value)
				push_b(head_a, head_b);
			else 
				rotate_a(head_a);
			if (list_size(head_b) > 1 && ((*head_b)->next)->value > (*head_b)->value)
					swap_b(head_b);
		}
		if (list_size(head_a) > 1)
			push_b(head_a, head_b);
		if (list_size(head_a) == 1)
			break;
	}
	while (list_size(head_a) != size)
	{	
		if ((*head_b)->value == largest_number(head_b))
			push_a(head_a, head_b);
		else
			rotate_b(head_b);
	}	
}


//int	main(void)
//{
//	t_node	a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
//	t_node	*head_a;
//	t_node	*head_b;
//
//	a1.value = 66;
//	a2.value = 17;
//	a3.value = 37;
//	a4.value = 21;
//	a5.value = 7;
//	a6.value = 42;
//	a7.value = 96;
//	a8.value = 27;
//	a9.value = 83;
//	a10.value = 74;
//	head_a = &a1;
//	a1.next = &a2;
//	a2.next = &a3;
//	a3.next = &a4;
//	a4.next = &a5;
//	a5.next = &a6;
//	a6.next = &a7;
//	a7.next = &a8;
//	a8.next = &a9;
//	a9.next = &a10;
//	a10.next = NULL;
//	head_b = NULL;
//
//	printf("Stack A\n");
//	print_node(head_a);
//	printf("\n");
//	printf("Stack B\n");
//	print_node(head_b);
//	printf("\n");
//	sorter(&head_a, &head_b);
//	printf("\n");
//
//	printf("Stack A\n");
//	print_node(head_a);
//	printf("\n");
//	printf("Stack B\n");
//	print_node(head_b);
//	
//	return (0);
//}
