#include "monty.h"

/**
 * _pint - prints the top for the stack
 * @stack: pointered to a stack
 * @n: line number that opcode is call at.
 */
void _pint(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pchar - prints out a char
 * @stack: pointered to a stack
 * @n: line number that opcode is call at.
 */
void _pchar(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}


/**
 * _pstr - prints a string
 * @stack: pointered to a stack
 * @n: line number that opcode is call at.
 */
void _pstr(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stdout, "\n");
		return;
	}

	node = *stack;
	while (node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		fprintf(stdout, "%c", node->n);
		node = node->next;
	}

	fprintf(stdout, "\n");
}

/**
 * _rotl -The top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 *
 * @stack: pointer to a stack
 * @n: line number
 */
void _rotl(stack_t **stack, unsigned int n)
{
	stack_t *head, *tail;
	(void) n;

	if (!stack || *stack)
		return;
	head = *stack;

	*stack = (*stack)->next;
	head->next = (*stack)->prev = NULL;

	tail = *stack;

	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
}
