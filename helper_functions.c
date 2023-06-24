#include "monty.h"

/**
 * free_stack - frees the stack nodes
 * @stack: pointer to the first node
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * isStringDigits - checks if value of stack is a digit or not
 * @str: the value for stack node
 * Return: true if value is digit, else false
 */
bool isStringDigits(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
