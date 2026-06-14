# Monty

An interpreter for Monty ByteCodes files, written in C. Monty 0.98 is a
scripting language compiled into Monty byte code files (`.m`). It relies
on a unique stack, with specific instructions to manipulate it.

## Usage

    ./monty file

where `file` is the path to a Monty bytecode file. Each line holds one
instruction; extra text after the opcode and its argument is ignored, and
blank lines or lines beginning with `#` are skipped.

## Compilation

    gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

or simply:

    make

## Opcodes

| Opcode | Description                                                    |
|--------|----------------------------------------------------------------|
| push   | Pushes an integer onto the stack: `push <int>`                 |
| pall   | Prints all values on the stack, top first                      |
| pint   | Prints the value at the top of the stack                       |
| pop    | Removes the top element of the stack                           |
| swap   | Swaps the top two elements of the stack                        |
| add    | Adds the top two elements; result stored in the second        |
| sub    | Subtracts the top element from the second top element          |
| div    | Divides the second top element by the top element              |
| mul    | Multiplies the second top element by the top element           |
| nop    | Does nothing                                                   |

Arithmetic and stack operations that need at least two elements print
`L<n>: can't <op>, stack too short` and exit on failure. `div` by zero
prints `L<n>: division by zero`. All error paths free the stack, free the
line buffer, and close the file before exiting `EXIT_FAILURE`.

## Files

| File          | Contents                                       |
|---------------|------------------------------------------------|
| monty.h       | Struct definitions and prototypes              |
| main.c        | Entry point and the read/execute loop          |
| monty_utils.c | Opcode lookup, stack freeing, clean exit       |
| opcodes1.c    | push, pall, pint, pop, swap                     |
| opcodes2.c    | add, nop, div, mul, sub                          |

## Authors

See [AUTHORS](AUTHORS).
