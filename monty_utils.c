#include "monty.h"

/**
 * get_op_func - matches an opcode string to its handler function
 * @opcode: the opcode read from the file
 *
 * Return: pointer to the handler, or NULL if the opcode is unknown
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"div", _div},
		{"mul", mul},
		{"sub", sub},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", set_stack},
		{"queue", set_queue},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * free_stack - frees every node of a stack_t doubly linked list
 * @stack: pointer to the top of the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * clean_exit - frees all resources and exits with failure status
 * @stack: pointer to the top of the stack to free
 *
 * Return: void (does not return; calls exit)
 */
void clean_exit(stack_t *stack)
{
	free_stack(stack);
	free(monty.line);
	if (monty.file != NULL)
		fclose(monty.file);
	exit(EXIT_FAILURE);
}

/**
 * is_integer - checks whether a string is a valid (optionally signed) integer
 * @s: the string to validate
 *
 * Return: 1 if s is a valid integer, 0 otherwise
 */
int is_integer(char *s)
{
	int i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	for (; s[i] != '\0'; i++)
	{
		if (!isdigit((unsigned char)s[i]))
			return (0);
	}
	return (1);
}
