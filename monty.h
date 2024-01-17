#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 *struct BusData_s - holds variables for arguments, file and line content
 *@argument: value of argument
 *@montyFile: points to monty file
 *@lineContent: line content
 *@stackFlag: flag that changes stack or queue
 *Description: carries values in program
 *
 */
typedef struct BusData_s
{
	char *argument;
	FILE *montyFile;
	char *lineContent;
	int stackFlag;
} BusData_t;

extern BusData_t bus;

char *reallocCustom(char *ptr, unsigned int oldSize, unsigned int newSize);
ssize_t getStdinCustom(char **lineBuffer, int file);
char *cleanLineContent(char *content);
void pushHandler(stack_t **head, unsigned int line_number);
void pallHandler(stack_t **head, unsigned int line_number);
void pintHandler(stack_t **head, unsigned int line_number);
int execInstruction(char *content, stack_t **head, unsigned int lineCounter,
		FILE *file);
void freeStack(stack_t *head);
void popHandler(stack_t **head, unsigned int lineCounter);
void swapHandler(stack_t **head, unsigned int lineCounter);
void addHandler(stack_t **head, unsigned int lineCounter);
void nopHandler(stack_t **head, unsigned int lineCounter);
void subHandler(stack_t **head, unsigned int lineCounter);
void divHandler(stack_t **head, unsigned int lineCounter);
void mulHandler(stack_t **head, unsigned int lineCounter);
void modHandler(stack_t **head, unsigned int lineCounter);
void pcharHandler(stack_t **head, unsigned int lineCounter);
void pstrHandler(stack_t **head, unsigned int lineCounter);
void rotHandler(stack_t **head, unsigned int lineCounter);
void rotrHandler(stack_t **head,
		__attribute__((unused)) unsigned int lineCounter);
void addNode(stack_t **head, int value);
void addQueue(stack_t **head, int value);
void queueHandler(stack_t **head, unsigned int lineCounter);
void stackHandler(stack_t **head, unsigned int lineCounter);

#endif

