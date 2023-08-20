#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: character string
 * Return: return int
 */
int _printf(const char *format, ...)
{
	int i = 0, nofb = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			put_char(format[i]);
			nofb += 1;
		}
		else
		{
			if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char*);

				nofb += putstr(str);
			}
			else if (format[i + 1] == 'c')
				nofb +=  put_char(va_arg(args, int));
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
				nofb += _putint(va_arg(args, int));
			else if (format[i + 1] == '%')
			{
				put_char('%');
				nofb += 1;
			}
			i++;
		}
	}
	va_end(args);
	return (nofb);
}
