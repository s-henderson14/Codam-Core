/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 13:47:09 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/22 13:47:13 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct node
{
	int			value;
	struct node	*next;
}t_node;

void	print_node(t_node *head);

void	add_front(t_node **list, t_node *new);

t_node	*node_init(int value);

int		ft_atoi(const char *str);

#endif
