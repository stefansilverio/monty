#include "monty.h"

/**
 * push - pushes a node to a stack
 * @stack: head of the stack
 * @n: line number
 */
void _push(stack_t **stack, unsigned int n)
{
	stack_t *node = NULL;
	(void) n;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->prev = node->next = NULL;

	if (!(*stack))
		(*stack) = node;
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
}

/**
 * pall - prints a stack
 * @stack: pointer to a stack_t
 * @n: line number
 */
void _pall(stack_t **stack, unsigned int n)
{
	(void) n;

	if (!stack || !(*stack))
		return;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}

/**
 * _swap - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @n: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int store = 0;

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, "L %u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	if ((*stack)->next == NULL)
		exit(EXIT_FAILURE);
	store = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = store;
}

/**
 * _add - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @n: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr->next == NULL)
		exit(EXIT_FAILURE);
	curr->next->n = (curr->next->n) + (curr->n);
	_pop(stack, line_number);
}

/**
 * _sub - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @n: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr->next == NULL)
		exit(EXIT_FAILURE);
	curr->next->n = (curr->next->n) - (curr->n);
	_pop(stack, line_number);
}

/**
 * _div - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @n: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr->next == NULL)
		exit(EXIT_FAILURE);
	if (curr->n == 0)
		exit(EXIT_FAILURE);
	curr->next->n = (curr->next->n) / (curr->n);
	_pop(stack, line_number);
}

/**
 * _mul - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @n: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr->next == NULL)
		exit(EXIT_FAILURE);
	if (curr->n == 0)
		exit(EXIT_FAILURE);
	curr->next->n = (curr->next->n) % (curr->n);
	_pop(stack, line_number);
}

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr->next == NULL)
		exit(EXIT_FAILURE);
	curr->next->n = (curr->next->n) * (curr->n);
	_pop(stack, line_number);
}

/**
 * pop - remove the top ele of a stack
 * @stack: pointer to top of a stack
 * @n: line number
 */
void _pop(stack_t **stack, unsigned int n)
{
	stack_t *node;

	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stdout, "Can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	node = *stack;

	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(node);
}
