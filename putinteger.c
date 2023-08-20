#include "main.h"

/**
 * putinteger - functionf to print an integer
 * @integer: input (int)
 * Return: count of numbers printed
 */

int putinteger(int integer)
{
	int nofb = 0; /*count of printed characters*/
	int div = 1;
	int x; /*digit to be printed*/

	if (integer < 0) /* handeling -ve numbers*/
	{
		integer = integer * (-1);
		put_char('-');
		nofb++;
	}
	while (integer / div > 9) /*finding no of digits */
	{
		div *= 10;
	}
	while (div > 0) /*printing number from left to right*/
	{
		x = integer / div;
		put_char(x + 48);
		integer %= div;
		div = div / 10;
		nofb++;
	}
	return (nofb);
}
