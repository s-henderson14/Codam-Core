/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:05:50 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:19:08 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **head)
{
	t_node	*tmp1;
	t_node	*last;
	t_node	*second_last;

	if (*head == NULL || (*head)->next ==NULL)
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
	write(1, "rra\n", 4);
}
