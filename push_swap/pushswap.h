/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 13:47:09 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 15:06:29 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct node
{
	int			value;
	struct node	*next;
	
}t_node;

void	swap_a(t_node **head);

void	swap_b(t_node **head);

void	rotate_a(t_node **head);

void	rotate_b(t_node **head);

void	reverse_rotate_a(t_node **head);

void	reverse_rotate_b(t_node **head);

void	push_a(t_node **head_a, t_node **head_b);

void	push_b(t_node **head_a, t_node **head_b); 

void	print_node(t_node *head);

void	add_front(t_node **list, t_node *new);

t_node	*node_init(int value);

int		ft_atoi(const char *str);

int		stack_size(t_node **head);

#endif
