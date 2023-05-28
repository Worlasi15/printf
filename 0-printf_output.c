#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - print character to the standard output
 * @c: preffered character to print
 *
 * Return: 1 On success, -1 on error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _printf - function that produces output according to a format
  * @format: arguments that is in var_list
  * Return: the number of characters printed
  * excluding the null byte used to end output to strings
  */
int _printf(const char *format, ...)
{
	va_list l;

	va_start(l, format);

	int char_print = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					{

						char c = (char)va_arg(l, int);

						char_print += _putchar(c);
						break;
					}
				case 's':
					{

						char *str = va_arg(l, char *);

				while (*str)
						{
							char_print += _putchar(*str);
							str++;
						}
						break;
					}
				case '%':
					{
						char_print += _putchar('%');
						break;
					}
				default:
					char_print += _putchar('%');
					char_print += _putchar(*format);
					break;
			}
		}
		else
		{
			char_print += _putchar(*format);
		}

		format++;
	}

	va_end(l);

	return (char_print);
}
