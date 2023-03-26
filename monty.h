#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
extern char *line;
extern FILE *file;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
char *line_parser(char *str);
instruct_func select_function(char *str);
void read_file(char *filename, stack_t **stack);
void free_dlinked_list(stack_t *head);
void print_all_elements(stack_t **head);
void print_element_at_head(stack_t **head, int num);
void print_letter_at_head(stack_t **head, int num);
void del_node_at_head(stack_t **head);
stack_t *add_node_at_head(stack_t **head, int n);
void exit_and_free(stack_t **stack);
stack_t *first_to_last(stack_t **stack);
size_t my_getline(char **lineptr, size_t *n, FILE *stream);
int isnumber(char *str);
#endif
