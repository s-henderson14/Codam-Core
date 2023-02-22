/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:53:26 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/22 16:37:43 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap_utils.c"

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;
	
	if ((*head_a)->value == NULL)
		exit(0);
	if ((*head_b)->value == NULL)
	{	
		(*head_a)->next == NULL;
		*head_b = *head_a;
	}
}		

int	main(void)
{
	t_node	*a1;
	t_node	*a2;
	t_node	*a3;
	t_node	*heada;
	t_node	*headb;
	t_node	*b1;
	t_node	*b2;
	t_node	*b3;
	
	//stack_a
	
	a1.value = 1;
	a2.value = 2;
	a3.value = 3;
	head_a = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = NULL;

	//stack_b
	//b1.value = 4;
	//b2.value = 5;
	//b3.value = 6;
	head_b->value = NULL;
	head_b->next = NULL;
	//b1.next = &b2;
	//b2.next = &b3;
	//b3.next = NULL;

	print_node(head_a);
	printf("\n");
	print_node(head_b);

	push_b(&head_a, &head_b);

	print_node(head_a);
	printf("\n");
	print_node(head_b);
	return (0);
}
