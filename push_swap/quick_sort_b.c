/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 13:13:26 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/24 14:59:40 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_node	**head_a, t_node **head_b, int elements)
{
	int	pivot;
	int	pushes;
	int	actions;

	pushes = 0;
	actions = 0;
	if (is_b_sorted(head_b))
	{	
		while (list_size(head_b) != 0)
			push_a(head_a, head_b);
	}
	while (!is_b_sorted(head_b))
	{	
		pivot = pivot_finder(head_b);
		while (actions < elements)
		{	
			if ((*head_b)->value > pivot)
			{	
				push_a(head_a, head_b);
				pushes++;
			}
			else 
				rotate_b(head_b);
			actions++;
