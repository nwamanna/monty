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
