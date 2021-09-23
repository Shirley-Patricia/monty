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
	int size = 0;

	if (line == NULL)
	{
		return (NULL);
	}
	size = count_word(line, " ");
	token = malloc(sizeof(char *) * (size + 1));
	if (!token)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token[0] = strtok(line, delimit);
	for (i = 1; i < size; i++)
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

#define OUT 0
#define IN 1

/**
 * count_word- word counter
 * @str: string a count.
 * @delim: delimitator.
 *
 * Return: a word.
 */
int count_word(char *str, char *delim)
{
	int count = OUT;
	int word = 0;

	while (*str)
	{
		if (*str == *delim || *str == '\n' || *str == '\t')
		{
			count = OUT;
		}
		else if (count == OUT)
		{
			count = IN;
			word++;
		}
		str++;
	}
	return (word);
}
