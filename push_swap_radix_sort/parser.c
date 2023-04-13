#include "push_swap.h"

int	parser(char *arg_string, t_node **head_a)
{
	int	i;
	int	j;
	char **split_args;

	i = 0;
	j = 0;
	split_args = ft_split(arg_string, ' ');
	while (split_args[i])
		i++;
	if (i == 1 && !valid_integer(arg_string))
		error_message();
	else if (i == 1)
		exit(0);
	else 
		stack_init(j, split_args, head_a);
	return (i + 1);
}
