/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 09:40:28 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/22 21:17:06 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **head)
{
	t_node	*mid;
	t_node	*last;

	mid = (*head)->next;
	last = last_node(*head);
	if ((*head)->value == largest_n(head) && mid->value > last->value)
	{	
		swap_a(head);
		reverse_rotate_a(head);
	}
	else if ((*head)->value == largest_n(head) && mid->value < last->value)
		rotate_a(head);
	else if (mid->value == largest_n(head) && (*head)->value > last->value)
		reverse_rotate_a(head);
	else if (mid->value == largest_n(head) && (*head)->value < last->value)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (last->value == largest_n(head) && (*head)->value > mid->value)
		swap_a(head);
}

/*int	main()
{
	t_node	n1, n2, n3;
	t_node	*head;

	n1.value = 2;
	n2.value = 9;
	n3.value = 3;
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	print_node(head);
	sort_three(&head);
	print_node(head);
	return (0);
}*/
