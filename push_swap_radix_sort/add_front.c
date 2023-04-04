/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_front.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 09:42:15 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/03 09:47:23 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_node **list, t_node *n)
{
	n->next = *list;
	*list = n;
}
