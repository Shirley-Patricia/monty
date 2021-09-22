#include "monty.h"

/**
 * get_op_func - Struct 
 * @s: The operator
 *
 * Return: 0
 */

int (*get_function(char *opcode))(stack_t **stack, unsigned int count_lines)
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
			(ops[i].f);
		else
			return (-1);
		i++;
	}
	return (0);
}