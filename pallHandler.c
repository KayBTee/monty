#include "monty.h"

/**
 * pallHandler - Prints the stack.
 * @head: Pointer to the stack head.
 * @lineNumber: Line number (not used).
 */
void pallHandler(stack_t **head, unsigned int lineNumber)
{
	stack_t *current;

	(void)lineNumber;

	current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

