#include "monty.h"

/**
 * read_lines - read lines of the monty file
 * @file: The operator
 *
 * Return: string
 */

char *read_lines(FILE *file)
{
	char *lines = NULL;
	size_t buf = 0;
	int num_char = 0;

	num_char = getline(&lines, &buf, file);
	if (lines == NULL)
	{
		printf("Error: malloc failed\n");
		free(lines);
		exit(EXIT_FAILURE);
	}
	if (num_char == -1)
		lines = NULL;
	return (lines);
}

/**
 * token_opcode - tokenize the lines of the monty file
 * @line: line to tokenize
 *
 * Return: string
 */

char **token_opcode(char *line)
{
	char **token = NULL;
	char *delimit = " \t\n";
	int i = 0;

	if (line == NULL)
	{
		return (NULL);
	}
	token = malloc(sizeof(char *) * 2 + 2);
	if (!token)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(token);
		exit(EXIT_FAILURE);
	}
	token[0] = strtok(line, delimit);
	for (i = 1; i < 2; i++)
	{
		token[i] = strtok(NULL, delimit);
	}
	return (token);
}

/**
 * isEmpty -  check if stack is empty
 * @root: doubly linked list
 *
 * Return: string
 */

int isEmpty(stack_t *root)
{
	return (!root);
}

/**
 * free_stack - free memory of a Doubly linked list.
 * @stack: head of the list
 *
 * Return: a integer.
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while ((temp = stack) != NULL)
	{
		stack = stack->next;
		free(temp);
	}
}
