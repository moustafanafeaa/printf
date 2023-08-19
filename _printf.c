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
			put_char(format[i]);
		}
		else if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
				{
					put_char(va_arg(args, int));
					break;
				}
				case 's':
				{
					str_nofb = putstr(va_arg(args, char*));
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
					put_char(format[i]);
					break;
				}
			}
			i += 1;
			nofb++;
		}
	}
	va_end(args);
	return (nofb);
}
