/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pivot_finder.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/17 09:54:26 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/17 10:20:54 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *pivot_finder(t_node **head)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		count;
	int		travel;

	tmp1 = *head;
	while (tmp1 != NULL)
	{	
		tmp2 = *head;
		count = 0;
		travel = 0;
		while (travel < list_size(head))
		{	
			if (tmp2->value < tmp1->value)
				count++;
			travel++;
			tmp2 = tmp2->next;
		}
		if (count == (list_size(head) / 2))
			return (tmp1);
		tmp1 = tmp1->next;
	}
	return (tmp1);
}

/*int	main()
{
	t_node	n1, n2, n3, n4, n5, n6, n7;
	t_node	*head;

	n1.value = 5;
	n2.value = 8;
	n3.value = 17;
	n4.value = 1;
	n5.value = 14;
	n6.value = 4;
	n7.value = 20;
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = NULL;
}*/
