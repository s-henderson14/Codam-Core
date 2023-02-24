/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_node.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:49:05 by shenders      #+#    #+#                 */
/*   Updated: 2023/02/24 14:49:09 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
