#include "monty.h"
/**
*main - entry point of program
*@argc: number of arguments passed on terminal
*@argv: list of argument passed
*
*Return: 0 on success
*/
int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_and_free(&stack);
	}
	read_file(argv[1], &stack);
	free_dlinked_list(stack);
	return (0);
}
