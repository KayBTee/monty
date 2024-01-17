#include "monty.h"

/**
 * addNode - Adds a node to the head of the stack.
 * @head: Pointer to the head of the stack.
 * @value: Value for the new node.
 */
void addNode(stack_t **head, int value)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head != NULL)
		(*head)->prev = newNode;

	*head = newNode;
}

