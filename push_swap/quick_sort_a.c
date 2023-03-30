/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sorter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 07:50:07 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/30 10:38:36 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_sort_a(t_node **head_a, t_node **head_b, int elements)
{
	int pushes;
	
	pushes = 0;
	if (is_a_sorted(head_a))
		exit(0);
	while (!is_a_sorted(head_a))
	{	
		if (pushes == 0)
			pushes += compare_pivot_a(head_a, head_b, elements);
		else
			pushes += compare_pivot_a(head_a,head_b, pushes);
	}
	pushes = 0;
	while (!is_b_sorted(head_b))	
		pushes += compare_pivot_b(head_a,head_b, list_size(head_b));	
}	

int	main()
{
	t_node	n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13; 
	t_node	*head_a;
	t_node	*head_b;

	n1.value = 32;
	n2.value = 3;
	n3.value = 88;
	n4.value = 18;
	n5.value = 65;
	n6.value = 37;
	n7.value = 4;
	n8.value = 6;
	n9.value = 75;
	n10.value = 5;
	n11.value = 19;
	n12.value= 53;
	n13. value = 2;
	head_a = &n1;
	head_b = NULL;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = &n11;
	n11.next = &n12;
	n12.next = &n13;
	n13.next = NULL;
	print_node(head_a);
	print_node(head_b);
	quick_sort_a(&head_a, &head_b, 6);
	print_node(head_a);
	printf("\n");
	print_node(head_b);
	return (0);
}
