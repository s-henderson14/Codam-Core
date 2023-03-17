/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_duplicate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 09:17:32 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/06 11:03:02 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_node **head, int value)
{
	t_node *tmp;

	tmp = *head;
	while (tmp != NULL)
	{	
		if (value == tmp->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}	
