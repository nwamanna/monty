#include "monty.h"
/**
*_mod- mod d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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

