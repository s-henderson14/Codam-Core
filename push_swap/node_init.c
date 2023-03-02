/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:48:21 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:15:13 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int value)
{
	t_node	*number;

	number = (t_node *)malloc(sizeof(t_node));
	if (!number)
		return (NULL);
	number->value = value;
	number->next = NULL;
	return (number);
}
