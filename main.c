#include "monty.h"

void main(__attribute__((unused)) int argc, char *argv[])
{
	unsigned int count_lines = 0, n = 0;
	char *line, **opcode;
	FILE *file;
	size_t size = 0;
	char *arg = argv[1];
	stack_t **stack = NULL;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	while ((line = read_lines(file)) != NULL)
	{
        opcode = token_opcode(line);
		count_lines++;
		data = atoi(opcode[1]);
		if (get_function(opcode[0])(stack, count_lines) == -1)
		{
			printf("L%u: unknown instruction %s", count_lines, opcode);
			exit(EXIT_FAILURE);
		}
	}
}