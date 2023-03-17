/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 10:15:58 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/17 17:36:31 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_node	*head_a;
	t_node	*node_a;
	t_node	*head_b;
	
	i = 1;
	if (argc <= 2)
		exit(0);
	while (i < argc)
	{		
		node_a = node_init(atoi(argv[i]));
		if ((is_duplicate(&head_a, node_a->value)) || node_a->value == 0) 
		{	
			write(2, "Error\n", 6);
			exit (0);
		}	
		add_back(&head_a, node_a);
		i++;
	}
	head_b = NULL;
	if (argc < 7)
	{	
		short_sort(&head_a, &head_a);
		return (0);
	}
	giga_sort(&head_a, &head_b);
	return (0);
}
