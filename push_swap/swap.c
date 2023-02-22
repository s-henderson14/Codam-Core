/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:54:00 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/22 13:56:29 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap_utils.c"

void	swap(t_node **head)
{	
	int		count;
	t_node	*tmp1;
	t_node	*tmp2;

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
}

int	main(void)
{
	t_node	n1;
	t_node	n2;
	t_node	n3;
	t_node	*head;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	print_node(head);
	printf("\n");
	print_node(head);
	return (0);
}
