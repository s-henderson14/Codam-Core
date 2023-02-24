/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:05:50 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 14:25:26 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.c"
#include "pushswap.h"

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
	write(1, "RRA\n", 4);
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
	head_a = NULL;
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

	printf("Stack A\n");
	print_node(head_a);
	printf("\n");
	reverse_rotate_a(&head_a);
	printf("Stack A\n");
	print_node(head_a);
	return (0);
}
