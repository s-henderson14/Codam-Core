/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_back.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 09:37:40 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/03 09:54:56 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_node **list, t_node *n)
{
	t_node	*tmp;

	tmp = *list;
	if (tmp == NULL)
	{	
		add_front(list, n);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = n;
	n = NULL;
}
