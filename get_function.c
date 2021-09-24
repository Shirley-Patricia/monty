#include "monty.h"

/**
 * get_function - get the different functions of opcode
 * @opcode: executable function
 * @count_lines: line number in file
 * @stack: stack structure
 *
 * Return: nothing
 */

void get_function(char *opcode, unsigned int count_lines, stack_t **stack)
{

	instruction_t ops[] = {
		{"pall", pall_function},
		{"pint", pint_function},
		{"pop", pop_function},
		{"swap", swap_function},
		{"add", add_function},
		{"nop", nop_function},
		{"sub", add_function},
		{NULL, NULL}
		};
	int i = 0;

	while (ops[i].opcode != NULL)
	{

		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			(ops[i].f)(stack, count_lines);
			break;
		}
		i++;
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", count_lines, opcode);
		exit(EXIT_FAILURE);
	}
}
