#ifndef STACK_INIT_H
# define STACK_INIT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int	value;
	struct node *next;
};
typedef struct node node_t;

void print_node(*head)
{

