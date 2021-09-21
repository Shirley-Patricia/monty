#include "monty.h"

void main(__attribute__((unused)) int argc, char *argv[])
{
	unsigned int count_lines = 0, n = 0;
	char *line, **opcode;
	FILE *file;
	size_t size = 0;
	char *arg = argv[1];

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
		printf("%s\n", (*opcode));
		n = atoi(opcode[1]);
		get_function(opcode[0])(n, count_lines);
	 	/*printf("%s", line);
	 	
		printf("%d", count_lines);*/
	}
}