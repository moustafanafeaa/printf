#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: character string
 * Return: return int
 */
int _printf(const char *format, ...)
{
	int i = 0, nofb = 0, str_nofb;
	va_list args;

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && !format[1])
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			put_char(va_arg(args, int));
		}
		else if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
				{
					int x = va_arg(args, int);

					put_char(x);
					break;
				}
				case 's':
				{
					str_nofb = putstr(va_arg(args, char*));
					i++;
					nofb = (nofb + str_nofb - 1);

					break;
				}
				case '%':
				{
					put_char('%');
					break;
				}
				default:
				{
					put_char(format[i + 1]);
					break;
				}
			}
			nofb++;
		}
	}
	va_end(args);
	return (0);
}
