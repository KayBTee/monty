#include "monty.h"

/**
 * mulHandler - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @lineCounter: Line number.
 */
void mulHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *current;
	int length = 0, result;

	current = *head;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

