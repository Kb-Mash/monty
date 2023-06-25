#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: the stack
 * @line_number: current working line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *secondTop = NULL;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	secondTop = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	secondTop->n %= top->n;

	pop(stack, line_number);
}

