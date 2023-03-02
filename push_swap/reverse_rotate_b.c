/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_b.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:06:43 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 15:06:25 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.c"
#include "pushswap.h"

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
	write(1, "RRB\n", 4);
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

	printf("Stack B\n");
	print_node(head_b);
	printf("\n");
	reverse_rotate_b(&head_b);
	printf("Stack B\n");
	print_node(head_b);
	return (0);
}