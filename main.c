#include "monty.h"

int main(int argc, char *argv[])
{
	unsigned int count_lines = 0;
	char *lines = NULL, **opcode = NULL;
	FILE *file = NULL;
	stack_t **stack = NULL;
	size_t buf = 0;
	int num_char = 0, data;


	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	num_char = getline(&lines, &buf, file);
	if (lines == NULL)
	{
		printf("Error: malloc failed\n");
		free(lines);
		exit(EXIT_FAILURE);
	}
	if (num_char == -1)
		lines = NULL;
	while (lines != NULL)
	{
        opcode = token_opcode(lines);
		count_lines++;
		data = atoi(opcode[1]);
		get_function(opcode[0], count_lines, stack);
	}
	return (data);
}