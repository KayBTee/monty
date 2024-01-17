#include "monty.h"
BusData_t bus = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.montyFile = file;
	if (!file)
	{
		fprintf(stderr, "Error; Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (bus.argument)
	{
		printf("Processing argument: %s\n", bus.argument);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.lineContent = content;
		counter++;
		if (read_line > 0)
		{
			executeInstruction(content, &stack, counter, file);
		}
		free(content);
	}
	freeStack(stack);
	fclose(file);
	return (0);
}
