#include "monty.h"

/**
 * push_function - add data in doubly linked list
 * @stack: stack structure
 * @line_number: number of line.
 * @glb_data: number to add to the list
 *
 * Return: nothing
 */

void push_function(stack_t **stack, char *glb_data, unsigned int line_number)
{
	stack_t *new_stack = NULL;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!glb_data || ((*glb_data) < 47 || (*glb_data) > 57))
	{
		if ((*glb_data) != 45)
		glb_data = NULL;
	}
	if (glb_data == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_stack->n = atoi(glb_data);
	new_stack->next = NULL;
	new_stack->prev = NULL;
	if (*stack != NULL)
	{
		new_stack->next = *stack;
		(*stack)->prev = new_stack;
		*stack = new_stack;
	}
	*stack = new_stack;
}

/**
 * pall_function - print all of the elements of a Doubly linked list.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void pall_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
	return;
	temp = (*stack);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_function - print the value at the top of a Doubly linked list.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void pint_function(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
