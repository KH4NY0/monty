#include "monty.h"

monty_t monty = {NULL, NULL, NULL};

/**
 * run_file - reads the Monty file line by line and runs each opcode
 *
 * Return: void
 */
void run_file(void)
{
size_t len = 0;
unsigned int line_number = 0;
char *opcode;
stack_t *stack = NULL;
void (*f)(stack_t **, unsigned int);

while (getline(&monty.line, &len, monty.file) != -1)
{
line_number++;
opcode = strtok(monty.line, " \t\n");
if (opcode == NULL || opcode[0] == '#')
continue;
monty.arg = strtok(NULL, " \t\n");
f = get_op_func(opcode);
if (f == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
line_number, opcode);
clean_exit(stack);
}
f(&stack, line_number);
}
free(monty.line);
free_stack(stack);
fclose(monty.file);
}

/**
 * main - entry point of the Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
monty.file = fopen(argv[1], "r");
if (monty.file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
run_file();
return (EXIT_SUCCESS);
}
