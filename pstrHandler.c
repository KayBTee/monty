#include "monty.h"

/**
 * pstrHandler - Prints the string starting at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @lineCounter: Line number.
 */
void pstrHandler(stack_t **head, unsigned int lineCounter)
{
	stack_t *temp;
	(void)lineCounter;

	temp = *head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			break;
		}
		putchar(temp->n);
		temp = temp->next;
	}

	putchar('\n');
}

