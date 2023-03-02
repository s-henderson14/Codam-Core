/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 11:33:53 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:23:22 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_node **head)
{
	int	count;
	t_node	*tmp1;
	t_node 	*tmp2;
	
	if (*head == NULL)
		exit(0);
	count = 0;
	tmp1 = *head;
	while (tmp1 != NULL)
	{
		tmp1 = tmp1->next;
		count++;
	}
	if (count < 2)
		exit(0);
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = tmp2->next;
	*head = tmp2;
	(*head)->next = tmp1;
	write(1, "SB\n", 3);
}
