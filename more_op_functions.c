#include "monty.h"

/**
 * add_function - adds the top two elements of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */
void add_function(stack_t **stack, unsigned int line_number)
{
stack_t *temp = NULL;
stack_t *current = NULL;
int len = 0;
int sum = 0;
	current = *stack;
	while (current != NULL)
{
		len++;
		current = current->next;
	}
	if (len < 2)
{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
}
temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
sum = temp->n + (*stack)->n;
(*stack)->n = sum;
free(temp);
}
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
 * sub_function - adds the top two elements of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */
void sub_function(stack_t **stack, unsigned int line_number)
{
stack_t *temp = NULL;
stack_t *current = NULL;
int len = 0;
int sub = 0;

	current = *stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
sub = (*stack)->n - temp->n;
(*stack)->n = sub;
free(temp);
}
