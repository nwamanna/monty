#include "monty.h"
/**
*read_file - opens file and reads the content
*@filename: name of file
*@stack: pointer to pointer of linked list
*
*Return: void
*/
void read_file(char *filename, stack_t **stack)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int n_read;
	int line_count = 1;
	char *command;
	instruct_func s;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit_and_free(stack);
	}
	while ((n_read = my_getline(&line, &len, file)) != -1)
	{
		command = line_parser(line);
		if (command == NULL || command[0] == '#')
		{
			line_count++;
			continue;
		}
		s = select_function(command);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, command);
			exit_and_free(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(line);
	if ((fclose(file)) == -1)
		exit(-1);
}
/**
*select_function - selects function to use
*@str: opcode to be passed
*
*Return: function pointer
*/
instruct_func select_function(char *str)
{
	int i;

	instruction_t instruct[] = {
			{"push", _push},
			{"pint", _pint},
			{"add", _add},
			{"swap", _swap},
			{"pop", _pop},
			{"pall", _pall},
			{"nop", _nop},
			{NULL, NULL}
	};

	i = 0;

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}
/**
*line_parser - tokenize the sentence on a line
*str: the sentense
*
*Return: a word, the opcode command
*/
char *line_parser(char *str)
{
	char *opcode;

	opcode = strtok(str, "\n ");
	if (opcode == NULL)
		return (NULL);
	return (opcode);
}

#define BUFFER_SIZE 1024
/**
*my_getline - gets character written on a line of a file
*@lineptr - pointer
*@n: number of characters
*@stream: file or source
*
*Return: number of characters read or -1 on failure
*/
size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
	}
	if (*lineptr == NULL)
	{
		return (-1);
	}
	pos = 0;

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (pos >= *n - 1)
		{
			*n += BUFFER_SIZE;
			*lineptr = (char *)realloc(*lineptr, *n);

			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		(*lineptr)[pos++] = (char)c;
	}
	if (c == EOF && pos == 0)
	{
		return (-1);
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
/**
*isnumber - checks if a word is a number
*@str: word to test
*
*Return: 1 on sucess, -1 on failure
*/
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

