#include "monty.h"
/**
*exit_and_free - frees all the malloced memory and exits the program
*@stack: pointer to pointer of double linked list
*
*Return: Void
*/
void exit_and_free(stack_t **stack)
{
	if (line)
		free(line);
	if (file)
		fclose(file);
	if (*stack != NULL)
		free_dlinked_list(*stack);
	exit(EXIT_FAILURE);
}
