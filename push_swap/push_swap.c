/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 10:15:58 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/03 15:32:22 by shenders      ########   odam.nl         */
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
		add_back(&head_a, node_a);
		i++;
	}
	head_b = NULL;
	sorter(&head_a, &head_b);
	return (0);
}
