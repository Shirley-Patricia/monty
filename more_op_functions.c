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
 * sub_function - subtracts the two top elements of the stack.
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

/**
 * div_function - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void div_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int len = 0;
	int div = 0;

	current = *stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	div = (*stack)->n / temp->n;
	(*stack)->n = div;
	free(temp);
}

/**
 * mul_function - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void mul_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int len = 0;
	int mul = 0;
	current = *stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	mul = (*stack)->n * temp->n;
	(*stack)->n = mul;
	free(temp);
}

/**
 * mod_function - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void mod_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int len = 0;
	int mod = 0;
	current = *stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	mod = (*stack)->n % temp->n;
	(*stack)->n = mod;
	free(temp);
}
