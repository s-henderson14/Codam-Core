/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_b.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:06:43 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:19:01 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_node **head)
{
	t_node	*tmp1;
	t_node	*second_last;
	t_node	*last;
	
	if (*head == NULL || (*head)->next == NULL)
		exit(0);
	tmp1 = *head;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	second_last = tmp1;
	last = tmp1->next;
	tmp1 = *head;
	*head = last;
	(*head)->next = tmp1;
	second_last->next = NULL;
	write(1, "rrb\n", 4);
}
