/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   link_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 14:23:25 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/22 16:31:05 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct	s_node{
	int				value;
	struct s_node	*next;
};
typedef struct node	t_node;

void	print_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

void	add_front(t_node **list, t_node *new)
{
	new->next = *list;
	*list = new;
}

void	add_back(t_node **list, t_node *new)
{
	t_node	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new = NULL;
}

int	list_size(t_node **list)
{	
	int		count;
	t_node	*tmp;

	count = 1;
	tmp = *list;
	if (!*list)
		return (0);
	if (tmp->next == NULL)
		return (count);
	while (tmp->next != NULL)
	{	
		tmp = tmp->next;
		count++;
	}
	return (count);
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
	printf("Node Count - %d\n", list_size(&head));
	printf("\n");
	add_back(&head, &n6);
	print_node(head);
	printf("Node Count - %d\n", list_size(&head));
	return (0);
}
