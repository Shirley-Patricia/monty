#include "monty.h"

/**
 * main - it run the monty file
 * @argc: count
 * @argv: array
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	unsigned int count_lines = 0;
	char *lines = NULL, **opcode = NULL;
	FILE *file = NULL;
	stack_t *stack = NULL;
	size_t buf = 0;
	int data = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&lines, &buf, file)) != -1)
	{
		if (lines == NULL)
		{
			printf("Error: malloc failed\n");
			free(lines);
			exit(EXIT_FAILURE);
		}
		opcode = token_opcode(lines);
		if (strcmp(opcode[0], "push") == 0)
		{
			data = atoi(opcode[1]);
			push_function(&stack, data);
		}
		else
			get_function(opcode[0], count_lines, &stack);
		count_lines++;
	}
	free(lines);
	return (0);
}
