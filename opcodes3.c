#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clean_exit(*stack);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		clean_exit(*stack);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL && current->n > 0 && current->n < 128)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack so the top element becomes the last
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *tail;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	top = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	*stack = top->next;
	(*stack)->prev = NULL;
	top->prev = tail;
	top->next = NULL;
	tail->next = top;
}

/**
 * rotr - rotates the stack so the last element becomes the top
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
}
