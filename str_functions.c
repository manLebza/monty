#include "monty.h"

/**
 * _strcmp -> Compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 of both strings are equal, and other values if not.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);

	return (0);
}

/**
 * _sch -> search if char is in string
 * @s: string to check
 * @c: char to find
 * Return: 0 if unsuccessful, 1 if successful
 */

int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			break;
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky -> slices string into tokens dependant on the delimite
 * @s: string to slice into parts
 * @d: delimiters
 * Return: first partition
 */

char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, g = 0;
	
	if (!s)
		s = ultimo;

	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + g;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + g;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			g++;
			i++;
		}
	}
	return (NULL);
}
