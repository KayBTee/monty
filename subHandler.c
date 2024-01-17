#include "monty.h"

/**
 * subHandler - Subtracts the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @lineCounter: Line number.
 */
void subHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *temp;
	int subtract;
	int node_count;

	temp = *head;
	node_count = 0;
	while (temp != NULL)
	{
		node_count++;
		temp = temp->next;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	subtract = temp->next->n - temp->n;
	temp->next->n = subtract;
	*head = temp->next;
	free(temp);
}

