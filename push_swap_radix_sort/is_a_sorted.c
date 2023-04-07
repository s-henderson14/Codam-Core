/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_a_sorted.c                                        :+:    :+:          */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 11:35:04 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/17 15:00:34 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_sorted(t_node **head_a)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		sorted;

	sorted = 0;
	tmp1 = *head_a;
	tmp2 = (*head_a)->next;
	while (tmp2 != NULL)
	{
		if (tmp1->value < (tmp2->value))
			sorted = 1;
		else
		{
			sorted = 0;
			break ;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	return (sorted);
}

/*int	main()
{
	t_node	n1, n2, n3;
	t_node	*head;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	printf("%d\n", is_a_sorted(&head));
	return (0);
}*/
