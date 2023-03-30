/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 11:33:25 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/30 09:53:30 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct node
{
	int			value;
	struct node	*next;
	
}t_node;

void 	giga_sort(t_node **head_a, t_node **head_b, int elements);

void	sorter_v1(t_node **head_a, t_node **head_b);

void	sort_three(t_node **head);

void short_sort(t_node **head_a, t_node **head_b);

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

void	add_back(t_node **list, t_node *new);

void	merge(t_node **head_a, t_node **head_b);

t_node	*node_init(int value);

t_node	*pivot_finder(t_node **head);

int		ft_atoi(const char *str);

int		list_size(t_node **head);

int		valid_integer(int c);

int		is_a_sorted(t_node **head_a);

int		is_b_sorted(t_node **head_b);

int		is_duplicate(t_node **head, int value);

int		largest_number(t_node **head);

int		compare_pivot_a(t_node **head_a, t_node **head_b, int elements);

int		compare_pivot_b(t_node **head_a, t_node **head_b, int elements);

t_node	*last_node(t_node *head);


#endif
