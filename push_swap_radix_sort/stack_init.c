#include "push_swap.h"

void	stack_init(int i, char **argv, t_node **head_a)
{
	t_node	*node_a;

	while (argv[i])
	{
		if (!valid_integer(argv[i]))
			error_message();
		node_a = node_init(ft_atoi(argv[i]));
		check_duplicate(head_a, node_a->value);
		add_back(head_a, node_a);
		i++;
	}
}
