#include "monty.h"

/**
 * _push -> pushes an element to the stack
 * @doubly: head of the linked list
 * @cline: line number in stack
 * Return : void
 */

void _push(stack_t **doubly, unsigned int cline)
{
	int n, x;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	for (x( = 0; vglo.arg[x]) && vglo.arg[x] != '-')
	{
		if (!isdigit(vglo.arg[x]) && vglo.arg[x] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall -> prints all values on stack
 * @doubly: head of linked list
 * @cline: line numbers
 * Return: void
 */

void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint -> prints the value at the top of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: void
 */

void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		drintf(2, " ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}

/**
 * _pop -> removes the top element in the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: void
 */

void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: cant pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap -> swaps the top two elements in the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: void
 */

void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next; m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: cant swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
