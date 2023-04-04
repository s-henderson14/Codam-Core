#include "push_swap.h"

void	rank_stack(t_node **head)
{	
	t_node	*tmp1;
	t_node	*tmp2;
	int	count;

	tmp1 = *head;
	while (tmp1 != NULL)
	{	
		tmp2 = *head;
		count = 0;
		while (tmp2 != NULL)
		{	
			if (tmp1->value < tmp2->value)
				count++;
			tmp2 = tmp2->next;
		}
		count++;
		tmp1->rank = list_size(head) - count;
		tmp1 = tmp1->next;
	}
}

/*int main(void)
{	
	t_node	n1, n2, n3, n4 , n5, n6, n7, n8, n9, n10;
	t_node	*head;

	n1.value = -8;
	n2.value = -4;
	n3.value = 0;
	n4.value = 2;
	n5.value = 6;
	n6.value = 10;
	n7.value = 14;
	n8.value = 37;
	n9.value = 99;
	n10.value = 170;
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = NULL;
	print_node (head);
	return (0);
}*/


