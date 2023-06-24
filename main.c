#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments passed
 * @argv: the list of arguments passed
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	FILE *file;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_interpreter(file, instructions);

	fclose(file);

	return (0);
}
