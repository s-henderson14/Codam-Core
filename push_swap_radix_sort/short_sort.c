/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 10:41:53 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/22 20:15:23 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
void short_sort(t_node **head_a, t_node **head_b)
{
	int	size;	
	
	if (is_a_sorted(head_a))
		exit(0);	
	size = list_size(head_a);
	if (list_size(head_a) == 5)
	{	
		push_b(head_a, head_b);
		push_b(head_a, head_b);
		sort_three(head_a);
		if ((*head_b)->value < (*head_b)->next->value)
			swap_b(head_b);
	}
	else if (list_size(head_a) == 4)
	{	
		push_b(head_a, head_b);
		sort_three(head_a);
	}
	else if (list_size(head_a) == 3)
		sort_three(head_a);
	while (list_size(head_a) != size)
		merge(head_a, head_b);
}

/*int	main()
{	
	t_node	n1, n2, n3, n4, n5;
	t_node	*head_a;
	t_node	*head_b;

	head_b = NULL;
	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	n4.value = 4;
	n5.value = 5;
	head_a = &n3;
	n3.next = &n1;
	n1.next = &n2;
	n2.next = &n5;
	n5.next = &n4;
	n4.next = NULL;
	print_node(head_a);
	short_sort(&head_a, &head_b);
	print_node(head_a);
}*/


	


