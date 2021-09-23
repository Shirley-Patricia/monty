#ifndef _MONTY_H_
#define _MONTY_H_
#define _POSIX_C_SOURCE 200809L


/*Libraries*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Structurs */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Prototypes*/

char *read_lines(FILE *file);
char **token_opcode(char *line);
void get_function(char *opcode, unsigned int count_lines, stack_t **stack);
int isEmpty(stack_t *root);
void free_stack(stack_t *stack);
int count_word(char *str, char *delim);
void push_function(stack_t **stack, char *glb_data, unsigned int line_number);
void pall_function(stack_t **stack, unsigned int line_number);
void pint_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **stack, unsigned int line_number);

#endif
