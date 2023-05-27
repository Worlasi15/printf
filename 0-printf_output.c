#include "main.h"
#include <stdarg.h>

/**
  * _printf - function that produces output according to a format
  * @format: a character string
  * Return: number of characters printed
  * excluding the null byte used to end output to strings
  */
int _printf(const char *format, ...)
{
	va_list l;
	int char_print = 0;

	va_start(l, format);

	while (*format)
	{
		if (*format == '%')
		{
			format ++;

			switch (*format)
			{
				case 'c':
					char_print += _putchar(va_arg(l, int));
					break;
				case 'b':
				{
					char *p = va_arg(l, char*);
						int k = 0;

						while (p[k])
						{
							char_print += _putchar(p[k]);
							k++;
						}
				}
				break;

				case '%':
				char_print += _putchar('%');
				break;
				default:
				_putchar(*format);
				_putchar('%');
					char_print += 2;
				break;
			}
		}
		else
		{
			char_print += _putchar(*format);
		}
		format ++;
	}
	va_end(l);
	return char_print;
}
