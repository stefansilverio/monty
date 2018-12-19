#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern unsigned int line_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *build_list(stack_t **head);
stack_t *add_node_start(stack_t **h, int n);
int call(char **tokens, stack_t **stack);
void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int n);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

#endif
