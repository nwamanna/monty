#include "monty.h"
/**
*add_node_at_head - adds node at the head of a doubly linked list
*@head: pointer to linked list
*@n: integer to be stored in list
*
*Return: pointer to list
*/
stack_t *add_node_at_head(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit_and_free(head);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}
/**
*del_node_at_head - deletes node at the head of a list
*@head: pointer to a double-linked list
*
*Return: Void
*/
void del_node_at_head(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
	{
		printf("Error");
		exit_and_free(head);
	}
	temp = *head;
	if (temp->next != NULL)
	{
		*head = temp->next;
		(*head)->prev = NULL;
		free(temp);
	}
	if (temp->next == NULL)
	{
		free(temp);
		*head = NULL;
	}
}
/**
*print_element_at_head - prints at the element at head
*@head: pointer to element
*@num: interger to be stored in list
*
*Return: void
*/
void print_element_at_head(stack_t **head, int num)
{
	stack_t *ptr = *head;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		exit_and_free(head);
	}
	printf("%d\n", ptr->n);
}
/**
*print_all_elements - prints all elements in a double linked list
*@head: pointer to element
*
*Return: void
*/
void print_all_elements(stack_t **head)
{
	stack_t *ptr = *head;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
*free_dlinked_list - frees the entire double linked list
*@head: pointer to element
*
*Return: void
*/
void free_dlinked_list(stack_t *head)
{
	stack_t *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
void first_to_last(stack_t **head)
{
	stack_t *temp = *head;
	stack_t *temp2 = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*head = (*head)->next;
	temp2->next = NULL;
	temp->next = temp2;
	temp2->prev = temp;
}
