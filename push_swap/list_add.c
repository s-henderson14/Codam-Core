#include <stdio.h>
#include <stdlib.h>

struct node{

	int			value;
	struct node	*next;
};
typedef struct node node_t;


:wq
void print_node(node_t *head)
{
	node_t *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

void add_front(node_t **list, node_t *new)
{
	new->next = *list;
	*list = new;
}
	
void add_back(node_t **list, node_t *new)
{
	node_t *tmp;

	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new = NULL;
}

int list_size(node_t **list)
{	
	int		count;
	node_t	*tmp;

	count = 1;
	tmp = *list;
	if (!*list)
		return(0);
	if (tmp->next == NULL)
		return (count);	
	while (tmp->next != NULL)
	{	
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	main()
{
	node_t	n1,n2,n3;
	node_t *head;
	node_t	n4;
	node_t	n5;
	node_t	n6;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	n4.value = 66;
	n5.value = 77;
	n6.value = 101;

	head = &n3;
	n3.next = &n1;
	n4.next = NULL;
	n2.next = &n4;
	n1.next = &n2;

	print_node(head);
	printf("Node Count - %d\n", list_size(&head));
	
	printf("\n");

	add_back(&head, &n6);
	print_node(head);
	printf("Node Count - %d\n", list_size(&head));
	
	return (0);
}


