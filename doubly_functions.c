#include "monty.h"

/**
 * add_dnodeint_end -> adds a node to the end of the doubly list
 * @head: head of the linked list
 * @n: data to store
 * Return: Doubly linked list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "ERROR: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	temp->n =n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 * add_dnodeint -> adds a node at the beginning of the list
 * @haed: first postioon of the list
 * @n: data to store
 * Return: doubly linked list
 */

stack_t **add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		dprintf(2, "ERROR: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;

