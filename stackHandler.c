#include "monty.h"

/**
 * stackHandler - Sets the stack mode.
 * @head: Pointer to the stack head.
 * @lineCounter: Line number (unused).
 */
void stackHandler(stack_t **head, unsigned int lineCounter)
{
	(void)head;
	(void)lineCounter;

	bus.stackFlag = 0;
}

