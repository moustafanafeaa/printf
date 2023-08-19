#include "main.h"
/**
 * put_char - func that print char
 * @c: input (char)
 *
 * Return: 1.
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
