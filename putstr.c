#include "main.h"

/**
 * putstr - function to print string format
 * @c: pointer to input string
 * Return: number of bytes printed
 */

int putstr(char *c)
{
	int index =  0;

	if (c)
	{
		for (index = 0; c[index] != '\0'; index++)
		{
			put_char(c[index]);
		}
	}
	return (index);
}
