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
	int	i;
	t_node	*head_a;
	t_node	*head_b;

	i = 1;
	head_a = NULL;
	if (argc < 2)
		exit(0);
	else if (argc == 2)
		argc = parser(argv[i], &head_a);
	else
		stack_init(i, argv, &head_a);
	head_b = NULL;
	if (argc < 7)
	{	
		short_sort(&head_a,&head_b);
		return (0);
	}
	radix_sort(&head_a, &head_b);
	free_stack(&head_a);
	return (0);
}
