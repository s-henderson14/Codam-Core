/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 11:33:23 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/02 15:22:38 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **head)
{
	int		count;
	t_node	*tmp1;
	t_node	*tmp2;

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
	tmp2->next = tmp1;
	*head = tmp2;
	write(1, "SA\n", 3);
}
