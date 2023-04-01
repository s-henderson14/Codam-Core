/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare_pivot_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 07:29:05 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/30 10:36:49 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_pivot_a(t_node **head_a, t_node **head_b, int elements)
{
	int	pivot;
	int	pushes;
	int	actions;

	pushes = 0;
	actions = 0;
	while (!is_a_sorted(head_a))
	{
		pivot = pivot_finder(head_a)->value;
		while (actions < elements)
		{
			if ((*head_a)->value < pivot)
			{	
				push_b(head_a,head_b);
				pushes++;
			}
			else
				rotate_a(head_a);
			actions++;
		}
		if (list_size(head_a) <= 5)
			short_sort(head_a,head_b);
		break ;
	}
	return (pushes);
}


