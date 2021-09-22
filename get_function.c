#include "monty.h"

/**
 * get_op_func - Struct 
 * @s: The operator
 *
 * Return: 0
 */

void get_function(char *opcode, unsigned int count_lines, stack_t **stack)
{

	instruction_t ops[] = {
		{"push", push_function},
		{"pall", pall_function},
		/*{"pop", pop_function},
		{"pint", pint_function},
		{"swap", swap_function},*/
		{NULL, NULL}};
	int i = 0;
	while (ops[i].opcode != NULL)
	{
		if (*opcode == *(ops[i].opcode))
		{
			(ops[i].f)(stack, count_lines);
			break;
		}
		i++;
	}
	printf("L%u: unknown instruction %s", count_lines, opcode);
	exit(EXIT_FAILURE);
}