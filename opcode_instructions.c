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
		drintf(2, " ",cline);
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


/**
 * _swap -> swaps the top two elements in the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: void
 */
