/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 09:40:28 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/16 13:59:36 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **head)
{
	t_node	*mid;
	t_node	*last;

	mid = (*head)->next;
	last = last_node(*head);
	if ((*head)->value > mid->value && mid->value > last->value) 
	{	
		swap_a(head);
		reverse_rotate_a(head);
	}
	else if ((*head)->value > mid->value && mid->value < last->value)
		rotate_a(head);
	else if ((*head)->value < mid->value && mid->value > last->value)
	{	
		swap_a(head);
		rotate_a(head);
	}
	else if ((*head)->value < mid->value && mid->value > last->value)
	   reverse_rotate_a(head);
	else if ((*head)->value > mid->value && (*head)->value < last->value)
		swap_a(head);
}	
