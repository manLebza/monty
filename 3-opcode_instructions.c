#include "monty.h"

/**
 * _div -> divides 2nd element by the 1st top element in a stack
 * @doubly: head of linked list
 * @cline: line number;
 * Return: void
 */

void _div(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: cant div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mul -> multiplies the top element by the second element from the top
 * @doubly: head of linked list
 * @cline: line number
 * Return: void
 */

void _mul(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: cant mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mod -> computes all divisions of the second element by top element on stack
 * @doubly: head of linked list
 * @cline: line number
 * Retrun: void
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: cant mod, stack is too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * pchar -> print char of the first element
 * @doubly: head of the linked list
 * @cline: line number.
 * Return: void
 */
void _pchar


/**
 * pstr -> prints string of the stack
 * @doubly: head of the list
 * @cline: line number
 * Return : void
 */
void _pstr
