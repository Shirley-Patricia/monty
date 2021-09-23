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
	unsigned int count_lines = 1;
	char *lines = NULL, *glb_data = NULL, **opcode = NULL;
	FILE *file = NULL;
	stack_t *stack = NULL;
	size_t buf = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&lines, &buf, file)) != -1)
	{
		if (lines == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(lines);
			exit(EXIT_FAILURE);
		}
		opcode = token_opcode(lines);
		if (opcode[0])
		{
			if (opcode[1])
				glb_data = opcode[1];
			if (strcmp(opcode[0], "push") == 0)
				push_function(&stack, glb_data, count_lines);
			else
				get_function(opcode[0], count_lines, &stack);
		}
		count_lines++;
	}
	free(lines);
	return (0);
}
