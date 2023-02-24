/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 12:01:33 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 10:42:54 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "push_swap_utils.c"


void rotate_a(t_node **head)	
{	
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*last;

	tmp1 = *head;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	last = tmp1;
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp2;
	write(1, "RA\n",3);
}

void rotate_b(t_node **head)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*last;

	tmp1 = *head;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	last = tmp1;
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp2;
	write(1, "RB\n", 3);
}

void	reverse_rotate_a(t_node **head)
{
	t_node	*tmp1;
	t_node	*last;
	t_node	*second_last;

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

void	reverse_rotate_b(t_node **head)
{
	t_node	*tmp1;
	t_node	*second_last;
	t_node	*last;

	tmp1 = *head;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	second_last = tmp1;
	last = tmp1->next;
	tmp1 = *head;
	*head = last;
	(*head)->next = tmp1;
	second_last->next = NULL;
}


int	main(void)
{
	t_node	n1;
	t_node	n2;
	t_node	n3;
	//t_node	n4;
	t_node	*head;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	//n4.value = 4;
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	//n4.next = NULL;
	print_node(head);
	printf("\n");
	reverse_rotate_b(&head);
	print_node(head);
	return (0);
}
