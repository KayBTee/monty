#include "monty.h"

/**
 * swapHandler - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @lineCounter: Line number.
 */
void swapHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}

