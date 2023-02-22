/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 13:56:52 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/22 14:05:32 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct s_node
{
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
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
}

void	add_front(t_node **list, t_node *new)
{
	new->next = *list;
	*list = new;
}

t_node	*node_init(int value)
{
	t_node	*number;

	number = (t_node *)malloc(sizeof(t_node));
	if (!number)
		return (NULL);
	number->value = value;
	number->next = NULL;
	return (number);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	minus;

	index = 0;
	number = 0;
	minus = 1;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == 45 || str[index] == 43)
	{
		if (str[index] == 45)
			minus = minus * (-1);
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
		number = (number * 10) + (str[index++] - '0');
	if (number > INT_MAX)
		return (-1);
	else if (number < INT_MIN)
		return (0);
	return (number * minus);
}

int	main(int argc, char **argv)
{	
	int		i;
	t_node	*head;
	t_node	*node;

	i = 1;
	if (argc <= 2)
		return (0);
	while (i < argc)
	{	
		node = node_init(atoi(argv[i]));
		add_front(&head, node);
		i++;
	}
	print_node(head);
	return (0);
}