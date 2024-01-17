#include "monty.h"

/**
 * rotrHandler - Rotates the stack to its bottom.
 * @head: Pointer to the stack head.
 * @lineCounter: Line number (unused).
 */
void rotrHandler(stack_t **head,
		__attribute__((unused)) unsigned int lineCounter)
{
	stack_t *cpy;

	cpy = *head;

	if (*head == NULL || (*head)->next == NULL)
		return;

	while (cpy->next)
		cpy = cpy->next;

	cpy->next = *head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*head)->prev = cpy;
	(*head) = cpy;
}

