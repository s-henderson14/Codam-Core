/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 11:31:27 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 13:45:03 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap_utils.c"

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (*head_a == NULL)
		exit(0);
	if (*head_b == NULL)
	{
		tmp1 = (*head_a)->next;
		(*head_a)->next = NULL;
		*head_b = *head_a;
		*head_a = tmp1;
		write(1, "PB\n", 3);
	}
	else
	{
		tmp1 = (*head_a)->next;
		tmp2 = *head_b;
		*head_b = *head_a;
		(*head_a)->next = tmp2;
		*head_a = tmp1;
		write(1, "PB\n", 3);
	}
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
	
	printf("Stack A\n");
	print_node(head_a);
	printf("\n");
	printf("Stack B\n");
	print_node(head_b);
	printf("\n");
	push_b(&head_a, &head_b);
	printf("\n");

	printf("Stack A\n");
	print_node(head_a);
	printf("\n");
	printf("Stack B\n");
	print_node(head_b);

	//push_b(&head_a, &head_b);
	//print_node(head_a);
	//printf("\n");
	//print_node(head_b);
	return (0);
}
