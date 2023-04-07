/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   largest_n.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 16:31:45 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 17:40:23 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	largest_n(t_node **head)
{
	t_node	*tmp;
	int		largest_num;

	tmp = *head;
	largest_num = tmp->value;
	while (tmp-> next != NULL)
	{	
		if ((tmp->next)->value > largest_num)
			largest_num = (tmp->next)->value;
		tmp = tmp->next;
	}
	return (largest_num);
}
