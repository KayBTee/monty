#include "monty.h"

/**
 * modHandler - Computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @head: Pointer to the stack head.
 * @lineCounter: Line number.
 */
void modHandler(stack_t **head, unsigned int lineCounter)
{
	int length = 0, result;
	stack_t *current;

	current = *head;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	result = current->next->n % current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

