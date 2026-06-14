#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean_exit(*stack);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: pointer to the top of the stack (unused)
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _div - divides the second top element by the top element
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clean_exit(*stack);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clean_exit(*stack);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element by the top element
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		clean_exit(*stack);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - subtracts the top element from the second top element
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean_exit(*stack);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
