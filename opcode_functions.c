#include "monty.h"

/**
 * push_function - Struct op
 * @s: The operator
 *
 * Return: 0
 */

void push_function(stack_t **stack, int data)
{
	stack_t *new_stack = NULL;
	
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_stack->n = data;
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
 * pall - function that print all of the elements of a Doubly linked list.
 * @stack: pointer to the list
 * @line_number: number of lines
 *
 * Return: nothing.
 */

void pall_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = (*stack);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}