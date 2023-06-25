#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: current working line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *secondTop = NULL;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	secondTop = top->next;
	secondTop->n += top->n;

	pop(stack, line_number);
}

/**
 * nop - doesn’t do anything
 * @stack: the stack
 * @line_number: current working line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: the stack
 * @line_number: current working line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *secondTop = NULL;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	secondTop = top->next;
	secondTop->n -= top->n;

	pop(stack, line_number);
}
