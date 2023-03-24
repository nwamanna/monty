#include "monty.h"
/**
*_push- adds an element at the top of a stack
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;

	arg = strtok(NULL, "\n ");
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_and_free(stack);
	}
	if (isnumber(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_and_free(stack);
	}
	value = atoi(arg);

	add_node_at_head(stack, value);
}

/**
*_pint- print first element in a stack
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	print_element_at_head(stack, line_number);
}

/**
*_pall- prints all elements in a stack
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	print_all_elements(stack);
}
/**
*_pop- deletes the first element in a stack
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_and_free(stack);
	}
	del_node_at_head(stack);
}
/**
*_swap- swaps the first 2 elements in a stack
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	int store;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_and_free(stack);
	}
	store = temp->n;
	temp->n = temp->next->n;
	temp->next->n = store;
}
