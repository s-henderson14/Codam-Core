/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_size_.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:49:27 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 14:49:30 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	stack_size(t_node **head)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
