#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
.git/int n;
.git/struct stack_s *prev;
.git/struct stack_s *next;
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
.git/char *opcode;
.git/void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - global interpreter state
 * @arg: argument string for the current opcode (e.g. the push value)
 * @line: line buffer returned by getline (kept for cleanup)
 * @file: opened Monty bytecode file (kept for cleanup)
 *
 * Description: single global variable holding everything the opcode
 * handlers need to clean up on a failed exit
 */
typedef struct monty_s
{
.git/char *arg;
.git/char *line;
.git/FILE *file;
} monty_t;

extern monty_t monty;

/* interpreter core */
void run_file(void);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
void free_stack(stack_t *stack);
void clean_exit(stack_t *stack);

/* opcodes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
