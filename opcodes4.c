#include "monty.h"

/**
 * set_stack - sets the data format to a stack (LIFO), the default mode
 * @stack: pointer to the top of the stack (unused)
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty.mode = 0;
}

/**
 * set_queue - sets the data format to a queue (FIFO)
 * @stack: pointer to the top of the stack (unused)
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty.mode = 1;
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clean_exit(*stack);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clean_exit(*stack);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
