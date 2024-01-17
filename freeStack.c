#include "monty.h"

/**
 * freeStack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack.
 */
void freeStack(stack_t *head)
{
	stack_t *temp;

	temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

