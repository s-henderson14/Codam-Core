/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_node.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:49:05 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:15:27 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
