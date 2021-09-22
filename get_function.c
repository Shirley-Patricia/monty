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
		{"pall", pall_function},
		/*{"pop", pop_function},
		{"push", push_function},
		{"pint", pint_function},
		{"swap", swap_function},*/
		{NULL, NULL}};
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
		printf("L%u: unknown instruction %s", count_lines, opcode);
		exit(EXIT_FAILURE);
	}
}