#include "monty.h"

/**
 * addQueue - Adds a node to the tail of the stack.
 * @head: Pointer to the stack head.
 * @n: Value for the new node.
 */
void addQueue(stack_t **head, int n)
{
	stack_t *newNode, *temp;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = NULL;

	temp = *head;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}

	if (!temp)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		temp->next = newNode;
		newNode->prev = temp;
	}
}

/**
 * queueHandler - Does nothing for now (placeholder).
 * @head: Pointer to the stack head.
 * @lineCounter: Line number.
 */
void queueHandler(stack_t **head, unsigned int lineCounter)
{
	(void)head;
	(void)lineCounter;
	bus.stackFlag = 1;
}

