#include "monty.h"

/**
 * divHandler - Divides the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @lineCounter: Line number.
 */
void divHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *hd;
	int length = 0;
	int temp;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	temp = hd->next->n / hd->n;
	hd->next->n = temp;
	*head = hd->next;
	free(hd);
}

