/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_node.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 13:51:26 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:49:33 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node *last_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
