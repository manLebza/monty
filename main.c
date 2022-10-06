#include "monty.h"

global_t vglo;

/**
 * free_vglo -> frees global variables
 * Return: void
 */

void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo -> initialises the global variables
 * @fd: file describtors
 * Return: void
 */

void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}

/**
 * check_input -> checks if file exists, or if it can be opened
 * @argc: arguement count
 * @argv: arguement vector
 * Return: file struct
 */

FILE *check_inut(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "ERROR: Cant oopen file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main -> Entry point
 * @argc: arguement count
 * @argv: arguement vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
