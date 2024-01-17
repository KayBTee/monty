#include "monty.h"

/**
 * pcharHandler - Prints the char at the top of the stack,
 * followed by a new line.
 * @head: Pointer to the stack head.
 * @lineCounter: Line number.
 */
void pcharHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *current;

	current = *head;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}

