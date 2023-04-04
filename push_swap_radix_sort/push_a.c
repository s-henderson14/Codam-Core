/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 10:59:34 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:15:39 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;
	
	if (*head_b == NULL)
		exit(0);
	if (*head_a == NULL)
	{
		tmp1 = (*head_b)->next;
		(*head_b)->next = NULL;
		*head_a = *head_b;
		*head_b = tmp1;
		write(1, "pa\n", 3);
	}
	else
	{
		tmp1 = (*head_b)->next;
		tmp2 = *head_a;
		*head_a = *head_b;
		(*head_b)->next = tmp2;
		*head_b = tmp1;
		write(1, "pa\n", 3);
	}	
}
