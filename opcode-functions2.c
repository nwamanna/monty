#include "monty.h"
/**
*_nop- does nothing
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
*_add- adds d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit_and_free(stack);
	}
	temp->next->n += temp->n;
	*stack = temp;
	_pop(stack, line_number);
}
/**
*_sub- sub d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit_and_free(stack);
	}
	temp->next->n -= temp->n;
	*stack = temp;
	_pop(stack, line_number);
}
/**
*_div- div d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit_and_free(stack);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_and_free(stack);
	}
	temp->next->n /= temp->n;
	*stack = temp;
	_pop(stack, line_number);
}
/**
*_mul- mul d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit_and_free(stack);
	}
	temp->next->n *= temp->n;
	*stack = temp;
	_pop(stack, line_number);
}
