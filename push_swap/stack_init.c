#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int	value;
	struct node *next;
};
typedef struct node  node_t;

void print_node(node_t *head)
{	
	node_t *tmp;

	tmp = head;
	while (tmp != NULL)
	{	
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
}

void add_front(node_t **list, node_t *new)
{
	new->next = *list;
	*list = new;
}

node_t *node_init(int value)
{
	node_t *number;

	number = (node_t*)malloc(sizeof(node_t));
	if (!number)
		return (NULL);
	number->value = value;
	number->next = NULL;
	return (number);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	minus;

	index = 0;
	number = 0;
	minus = 1;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == 45 || str[index] == 43)
	{
		if (str[index] == 45)
			minus = minus * (-1);
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
		number = (number * 10) + (str[index++] - '0');
	if (number > INT_MAX)
		return (-1);
	else if (number < INT_MIN)
		return (0);
	return (number * minus);
}

int main (int argc, char **argv)
{	
	int	i;
	node_t	*head;
	node_t	*node;

	i = 1;
	if (argc <= 2)
		return (0);

	while (i < argc)
	{	
		node = node_init(atoi(argv[i]));
		add_front(&head, node);
		i++;
		//printf("%d", node->value);
	}
	print_node(head);

	return (0);
}
	

