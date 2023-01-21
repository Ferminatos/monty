#include "monty.h"

/**
 * mod_nodes -  computes the rest of the division of the second top element of
 * the stack by the top element of the stack
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		more_err(11, line_number);

	ascii = (*stack)->n;

	if (ascii < 0 || ascii > 127)
	more_err(10, line_number);

	printf("%c\n", ascii);
}
