#include "monty.h"

/**
 * execute_interpreter - runs the interpreter for Monty Bytecodes files
 * @file: Monty Bytecodes file
 * @instructions: an array of opcode names and their functions
 */
void execute_interpreter(FILE *file, instruction_t *instructions)
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL;
	size_t n = 0;
	int i = 0, j;
	bool found;

	while (getline(&line, &n, file) != -1)
	{
		line_number++, args[i] = strtok(line, " \t\n");
		if (args[i] == NULL || strncmp(args[i], "#", 1) == 0)
			continue;
		while (args[i] != NULL)
			args[++i] = strtok(NULL, " \t\n");
		args[i] = NULL;
		found = false;
		for (j = 0; instructions[j].opcode != NULL; j++)
		{
			if (strcmp(args[0], instructions[j].opcode) == 0)
			{
				instructions[j].f(&stack, line_number);
				found = true;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, args[0]);
			exit(EXIT_FAILURE);
		}

		i = 0;
	}

	if (line != NULL)
		free(line);
	free_stack(stack);
}
