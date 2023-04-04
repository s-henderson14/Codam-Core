/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_b.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:02:57 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:19:13 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_b(t_node **head)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		exit(0);
	tmp1 = *head;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	last = tmp1;
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp2;
	write(1, "rb\n", 3);
}
