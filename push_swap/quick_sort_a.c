/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:43:20 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/24 15:15:16 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_node	**head_a, t_node **head_b, int elements)
{
	int	pivot;
	int	actions;

	actions = 0;
	if (is_b_sorted(head_b))
	{
		while (list_size(head_b) != 0)
			push_a(head_a, head_b);
	}
	while (!is_b_sorted(head_b))
	{
		pivot = pivot_finder(head_b)->value;
		while (actions < elements)
		{
			if ((*head_b)->value > pivot)
				push_a(head_a, head_b);
			else
				rotate_b(head_b);
			actions++;
			}

	}
	push_a(head_a,head_b);
}
void	quick_sort_a(t_node **head_a, t_node **head_b, int elements)
{
	int	pivot;
	int	pushes;
	int	actions;

	pushes = 0;
	actions = 0;
	if (is_a_sorted(head_a))
		exit(0);
	while (!is_a_sorted(head_a))
	{	
		pivot = pivot_finder(head_a)->value;
		elements = list_size(head_a);		
		while (actions < elements)
		{	
			if ((*head_a)->value < pivot)
			{	
				push_b(head_a, head_b);
				pushes++;
			}
			else 
				rotate_a(head_a);
			actions++;
		}
		if (list_size(head_a) <= 5)
		{	
			short_sort(head_a, head_b);
			break ;
		}
		actions = 0;
	}
	quick_sort_b(head_a, head_b, pushes);
}

int	main()
{
	t_node	n1, n2, n3, n4, n5, n6;
	t_node	*head_a;
	t_node	*head_b;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	n4.value = 4;
	n5.value = 19;
	n6.value = 6;
	head_a = &n2;
	head_b = NULL;
	n2.next = &n1;
	n1.next = &n5;
	n5.next = &n3;
	n3.next = &n4;
	n4.next = &n6;
	n6.next = NULL;
	print_node(head_a);
	print_node(head_b);
	quick_sort_a(&head_a, &head_b, 6);
	print_node(head_a);
	printf("\n");
	print_node(head_b);
	return (0);
}





