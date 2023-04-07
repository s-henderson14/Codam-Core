#include "push_swap.h"

void	free_stack(t_node **head_a)
{
	t_node	*tmp;
	
	if (!head_a)
		return ;
	tmp = *head_a;
	while (tmp != NULL)
	{
		tmp = (*head_a)->next;
		free(*head_a);
		*head_a = tmp;
	}
	*head_a = NULL;
}
