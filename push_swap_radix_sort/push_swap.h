/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 11:33:25 by shenders      #+#    #+#                 */
/*   Updated: 2023/04/13 20:15:20 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

typedef struct node
{
	int			value;
	int			rank;
	struct node	*next;

}t_node;

int		parser(char *arg_string, t_node **head_a);

void	error_message(void);

void	stack_init(int i, char **argv, t_node **head_a);

void	free_stack(t_node **head_a);

void	radix_sort(t_node **head_a, t_node **head_b);

void	sort_three(t_node **head);

void	short_sort(t_node **head_a, t_node **head_b);

void	swap_a(t_node **head);

void	swap_b(t_node **head);

void	rotate_a(t_node **head);

void	rotate_b(t_node **head);

void	reverse_rotate_a(t_node **head);

void	reverse_rotate_b(t_node **head);

void	push_a(t_node **head_a, t_node **head_b);

void	push_b(t_node **head_a, t_node **head_b);

void	merge(t_node **head_a, t_node **head_b);

void	rank_stack(t_node **head);

int		atoi(const char *str);

int		valid_integer(char *str);

int		is_a_sorted(t_node **head_a);

int		check_duplicate(t_node **head, int value);

int		largest_n(t_node **head);

t_node	*node_init(int value);

t_node	*last_node(t_node *head);

void	add_front(t_node **lst, t_node *new);

void	add_back(t_node **lst, t_node *new);

int		listsize(t_node *lst);
#endif
