#include "pushswap.h"

void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (*head_b == NULL)
		exit(0);
	if (*head_a == NULL)
	{
		tmp1 = (*head_b)->next;
		(*head_b)->next = NULL;
		*head_a = *head_b;
		*head_b = tmp1;
		write(1, "PA\n", 3);
	}
	else
	{
		tmp1 = (*head_b)->next;
		tmp2 = *head_a;
		*head_a = *head_b;
		(*head_b)->next = tmp2;
		*head_b = tmp1;
		write(1, "PA\n", 3);
	}

}

void rotate_a(t_node **head)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		exit(0);
	tmp1 = *head;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	last = tmp1;
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp2;
	write(1, "RA\n",3);
}

void rotate_b(t_node **head)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		exit(0);
	tmp1 = *head;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	last = tmp1;
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp2;
	write(1, "RB\n", 3);
}

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (*head_a == NULL)
		exit(0);
	if (*head_b == NULL)
	{
		tmp1 = (*head_a)->next;
		(*head_a)->next = NULL;
		*head_b = *head_a;
		*head_a = tmp1;
		write(1, "PB\n", 3);
	}
	else
	{
		tmp1 = (*head_a)->next;
		tmp2 = *head_b;
		*head_b = *head_a;
		(*head_a)->next = tmp2;
		*head_a = tmp1;
		write(1, "PB\n", 3);
	}
}


void	swap_b(t_node **head)
{
	int	count;
	t_node	*tmp1;
	t_node 	*tmp2;

	if (*head == NULL)
		exit(0);
	count = 0;
	tmp1 = *head;
	while (tmp1 != NULL)
	{
		tmp1 = tmp1->next;
		count++;
	}
	if (count < 2)
		exit(0);
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = tmp2->next;
	*head = tmp2;
	(*head)->next = tmp1;
	write(1, "SB\n", 3);
}
void	swap_a(t_node **head)
{
	int		count;
	t_node	*tmp1;
	t_node	*tmp2;

	if (*head == NULL)
		exit(0);
	count = 0;
	tmp1 = *head;
	while (tmp1 != NULL)
	{
		tmp1 = tmp1->next;
		count++;
	}
	if (count < 2)
		exit(0);
	tmp1 = *head;
	tmp2 = (*head)->next;
	(*head)->next = tmp2->next;
	tmp2->next = tmp1;
	*head = tmp2;
	write(1, "SA\n", 3);
}

int	list_size(t_node **list)
{
	int		count;
	t_node	*tmp;

	count = 1;
	tmp = *list;
	if (!*list)
		return (0);
	if (tmp->next == NULL)
		return (count);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void push_swap(t_node **head_a, t_node **head_b)
{
	t_node	*pivot;

	pivot = *head_a;
	while (pivot->next != NULL)
		pivot = pivot->next;
	while (list_size(head_a) != 1)
	{
		if ((*head_a)->value < pivot->value)
			push_b(head_a, head_b);
		else rotate_a(head_a);
	}	
}

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

int	main(void)
{
	t_node	a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
	t_node	*head_a;
	t_node	*head_b;

	a1.value = 66;
	a2.value = 17;
	a3.value = 37;
	a4.value = 21;
	a5.value = 7;
	a6.value = 42;
	a7.value = 96;
	a8.value = 27;
	a9.value = 83;
	a10.value = 74;
	head_a = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;
	a7.next = &a8;
	a8.next = &a9;
	a9.next = &a10;
	a10.next = NULL;
	head_b = NULL;

	printf("Stack A\n");
	print_node(head_a);
	printf("\n");
	printf("Stack B\n");
	print_node(head_b);
	printf("\n");
	push_swap(&head_a, &head_b);
	printf("\n");

	printf("Stack A\n");
	print_node(head_a);
	printf("\n");
	printf("Stack B\n");
	print_node(head_b);

	//push_a(&head_a, &head_b);
	//print_node(head_a);
	//printf("\n");
	//print_node(head_b);
	return (0);
}
