#include "monty.h"

/**
 * push - pushes an integer onto the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *tail;

	if (monty.arg == NULL || !is_integer(monty.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		clean_exit(*stack);
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_exit(*stack);
	}
	node->n = atoi(monty.arg);
	node->prev = NULL;
	node->next = NULL;
	if (monty.mode == 0 || *stack == NULL)
	{
		node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = node;
		*stack = node;
		return;
	}
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = node;
	node->prev = tail;
}

/**
 * pall - prints every value on the stack, top first
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clean_exit(*stack);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		clean_exit(*stack);
	}
	top = *stack;
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clean_exit(*stack);
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}
