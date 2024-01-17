#include "monty.h"

/**
 * pintHandler - Prints the top element of the stack.
 * @head: Pointer to the stack head.
 * @lineNumber: Line number.
 */
void pintHandler(stack_t **head, unsigned int lineNumber)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

