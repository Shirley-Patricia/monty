#include "monty.h"

/**
 * nop_function - does not do anythig.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */
void nop_function(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void pchar_function(stack_t **stack, unsigned int line_number)
{
	if (isEmpty(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 32 && (*stack)->n <= 126)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
