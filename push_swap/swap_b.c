/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 11:33:53 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 13:01:15 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap_utils.c"
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

int	main(void)
{
	t_node	a1;
	t_node	a2;
	t_node	a3;
	t_node	*head_a;
	t_node	*head_b;
	t_node	b1;
	t_node	b2;
	t_node	b3;

	a1.value = 1;
	a2.value = 2;
	a3.value = 3;
	head_a = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = NULL;
	b1.value = 4;
	b2.value = 5;
	b3.value = 6;
	head_b = &b1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = NULL;
	
	print_node(head_a);
	printf("\n");
	//swap_b(&head_a);
	swap_b(&head_a);
	print_node(head_a);
	printf("\n");
	return (0);
}
