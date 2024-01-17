#include "monty.h"

/**
 * pushHandler - Adds a node to the stack.
 * @head: Pointer to the head of the stack.
 * @lineCounter: Line number.
 */
void pushHandler(stack_t **head, unsigned int lineCounter)
{
	int n, j = 0, flag = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
			j++;
		for (; bus.argument[j] != '\0'; j++)
		{
			if (bus.argument[j] > '9' || bus.argument[j] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineCounter);
			fclose(bus.montyFile);
			free(bus.lineContent);
			freeStack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineCounter);
		fclose(bus.montyFile);
		free(bus.lineContent);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.argument);
	if (bus.stackFlag == 0)
		addNode(head, n);
	else
		addQueue(head, n);
}

