/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_b_sorted.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:24:28 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/08 14:37:01 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_b_sorted(t_node **head_a)
{
	t_node	*tmp;
	int		sorted;

	sorted = 0;
	tmp = *head_a;
	while (tmp->next != NULL)
	{
		if (tmp->value > (tmp->next)->value)
			sorted = 1;
		else
		{
			sorted = 0;
			break;
		}
		tmp = tmp->next;
	}
	return (sorted);
}
