/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 11:31:27 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:15:52 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (*head_a == NULL)
		exit(0);
	if (*head_b == NULL)
	{
		tmp1 = (*head_a)->next;
		(*head_a)->next = NULL;
		*head_b = *head_a;
		*head_a = tmp1;
		write(1, "pb\n", 3);
	}
	else
	{
		tmp1 = (*head_a)->next;
		tmp2 = *head_b;
		*head_b = *head_a;
		(*head_a)->next = tmp2;
		*head_a = tmp1;
		write(1, "pb\n", 3);
	}
}
