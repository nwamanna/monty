#include "monty.h"
/**
*first_to_last - puts the first element of a stack as the last
*@head: pointer to pointer of double linked list
*
*Return: pointer to double linked list
*/
stack_t *first_to_last(stack_t **head)
{
	stack_t *temp;
	stack_t *temp2;

	if (*head == NULL)
		exit_and_free(head);
	if ((*head)->next == NULL)
		return (*head);
	temp = *head;
	temp2 = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*head = (*head)->next;
	temp2->next = NULL;
	temp->next = temp2;
	temp2->prev = temp;
	return (*head);
}
/**
*print_letter_at_head - prints at the letter at head
*@head: pointer to element
*@num: line number command was found
*
*Return: void
*/
void print_letter_at_head(stack_t **head, int num)
{
	stack_t *ptr = *head;
	int value;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		exit_and_free(head);
	}
	value = ptr->n;
	if ((value < 65 || value > 91) && (value < 97 || value > 122))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		exit_and_free(head);
	}
	printf("%c\n", value);
}

