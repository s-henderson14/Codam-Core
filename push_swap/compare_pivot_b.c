/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare_pivot_b.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 08:01:09 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/30 10:40:26 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_pivot_b(t_node **head_a,t_node **head_b, int elements)
{	
	int	pivot;
	int pushes;
	int actions;

	pushes = 0;
	actions= 0;
	if (is_b_sorted(head_b))
	{
		while (list_size(head_b) != 0)
		   push_a(head_a,head_b);
	}	
	while (!is_b_sorted(head_b))
	{	
		pivot = pivot_finder(head_b)->value;
		while (actions < elements)
		{
			if ((*head_b)->value > pivot)
			{
				push_b(head_a,head_b);
				pushes++;
			}
			else 
				rotate_b(head_b);
			actions++;
		}
		if (list_size(head_b) <= 5)
			short_sort(head_b,head_a);
		break ;
	}
	return (pushes);
}	
