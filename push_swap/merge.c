/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/17 12:26:12 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/22 20:33:01 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_node **head_a, t_node **head_b)
{
	t_node *last;
	t_node *mid;

	last = last_node(*head_a);
	mid = (*head_a)->next;
	if ((*head_b)->value > (*head_a)->value && (*head_b)->value < mid->value)
	{
		push_a(head_a, head_b);
		swap_a(head_a);
	}
	else if ((*head_b)->value > mid->value && (*head_b)->value < last->value)
	{	
		rotate_a(head_a);
		push_a(head_a, head_b);
		swap_a(head_a);
		reverse_rotate_a(head_a);
	}
	else if ((*head_b)->value < (*head_a)->value)
		push_a(head_a, head_b);
	else if ((*head_b)->value > last->value)
	{
		push_a(head_a, head_b);
		rotate_a(head_a);
	}
}
