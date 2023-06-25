#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: current working line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (isStringDigits(args[1]) == false || args[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(args[1]);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
