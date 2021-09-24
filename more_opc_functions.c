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

/**
 * pchar_function - prints the char at the top of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

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

/**
 * pchar_function - prints the char at the top of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void pstr_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (isEmpty(*stack))
	{
		printf("\n");
		return;
	}

	temp = (*stack);
	while (temp != NULL && temp->n >= 32 && temp->n <= 126)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
