#include "main.h"
/*
 * _putint - kkasa
 * @n: ae
 * Return:  ad 
 */
int _putint(int num)
{
    int nofb = 0, digit, divisor = 1;

    if (num < 0)
    {
        put_char('-');
        num = -num;
        nofb++;
    }

    while (num / divisor > 9)
        divisor *= 10;

    while (divisor > 0)
    {
        digit = num / divisor;
        put_char('0' + digit);
        num %= divisor;
        divisor /= 10;
        nofb++;
    }

    return nofb;
}
