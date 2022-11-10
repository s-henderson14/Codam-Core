#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst;
	while (tmp != NULL)
	{	
		if (tmp->next == NULL)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (tmp);
}
