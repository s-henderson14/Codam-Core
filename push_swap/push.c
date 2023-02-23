/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:53:26 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/23 11:10:54 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap_utils.c"

void	push_to_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;
	
	if (*head_a == NULL)
		exit(0);
	if (*head_b == NULL)
	{	
		tmp1 = (*head_a)->next;		// Stored address of second node in variable called tmp.
		(*head_a)->next = NULL;		// Made the next pointer of the first node equal to NULL, Thus removing it from stack_a.
		*head_b = *head_a;			// Pointing the head pointer from stack_b towards the node which was severed from stack_a.
		*head_a = tmp1;				// Pointing the head pointer from stack_a to the (formerly second, now first) node of stack_a.
	}
	else
	{	
		tmp1 = (*head_a)->next;
		tmp2 = *head_b;
		*head_b = *head_a;
		(*head_a)->next = tmp2;
		*head_a = tmp1;
	}
}

void	push_to_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (*head_b == NULL)
		exit(0);
	if (*head_a == NULL)
	{	
		tmp1 = (*head_b)->next;
		(*head_b)->next = NULL;
		*head_a = *head_b;
		*head_b = tmp1;
	}
	else
	{	
		tmp1 = (*head_b)->next;		// Store address of stack_b's second node in variable called tmp1.
		tmp2 = *head_a;				// Store address of stack_a's first node in variable called tmp2;
		*head_a = *head_b;			// Pointing head pointer from stack_a towards first element of stack_b.
		(*head_b)->next = tmp2;	// Pointing the next pointer from head_b towards the formerly first, now 
		*head_b = tmp1;
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
	
	//stack_a
	
	a1.value = 1;
	a2.value = 2;
	a3.value = 3;
	head_a = NULL;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = NULL;

	//stack_b
	b1.value = 4;
	b2.value = 5;
	b3.value = 6;
	head_b = &b1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = NULL;
	
	printf("Stack_A\n");
	print_node(head_a);
	printf("\n");
	printf("Stack_B\n");
	print_node(head_b);

	push_to_a(&head_a, &head_b);
	push_to_a(&head_a, &head_b);
	//push_to_b(&head_a, &head_b);
	//push_to_b(&head_a, &head_b);
	printf("\n");
	printf("After pushing to a\n");
	//printf("After pushing to b\n"); 
	printf("Stack_A\n");
	print_node(head_a);
	printf("\n");
	printf("Stack_B\n");
	print_node(head_b);
	return (0);
}
