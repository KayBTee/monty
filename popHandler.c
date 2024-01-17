#include "monty.h"

/**
 * popHandler - Removes the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @lineCounter: Line number.
 */
void popHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}

