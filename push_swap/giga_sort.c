/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   giga_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 18:03:36 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/22 20:08:08 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	giga_sort(t_node **head_a, t_node **head_b)
{
 	int		size;
	int		largest;
	int		median;
	t_node	*pivot;
	t_node	*floor;

	size = list_size(head_a);
	if (is_a_sorted(head_a))
		exit(0);
	while (!is_a_sorted(head_a))
	{	
		pivot = pivot_finder(head_a);
		printf ("I am the pivot and I am %d!", pivot->value);
		while (*head_a != pivot)
		{	
			if ((*head_a)->value < pivot->value)
				push_b(head_a, head_b);
			else
				rotate_a(head_a);
			if (list_size(head_b) > 1)
			{	
				floor = last_node(*head_b);
				if (((*head_b)->next)->value > (*head_b)->value)
					swap_b(head_b);
				else if ((*head_b)->value < floor->value)
					rotate_b(head_b);
			}
		}
		if (list_size(head_a) > 1)
			push_b(head_a, head_b);
		if (list_size(head_a) == 1)
			break ;
	}
	while (list_size(head_a) != size && list_size(head_b) > 1)
	{	
		largest = largest_number(head_b);
		median = largest / 2;
		if ((*head_b)->value < (*head_b)->next->value)
			swap_b(head_b);
		if ((*head_b)->value >= median)
		{	
			push_a(head_a, head_b);
			if ((*head_a)->value > (*head_a)->next->value)
				swap_a(head_a);
		}
		else
			rotate_b(head_b);
	}
	if (!is_a_sorted(head_a))
		giga_sort(head_a, head_b);
	push_a(head_a, head_b);
}
