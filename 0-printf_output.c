#include "main.h"

int _printf(const char *format, ...);

#include <stdarg.h>
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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
				{
					case 'c':
						{
							char_print += _putchar(va_arg(l, int));
							break;
						}
					case 'b':
						{
							int k = 0;
							char *p = va_arg(l, char*);
					while (p[k])
					{
						char_print += _putchar(p[k]);
						k++;
								break;
					}
							case '%':
							{
								char_print += _putchar('%');
								break;
							}
							default:
							{
								_putchar(*format);
									_putchar('%');
									char_print += 2;
								break;
							}
						}
						format++;
				}
		}else
			{
				char_print += _putchar(*format);
				{
					format++;
				}
				va_end(l);

				return (char_print);

				va_end(l);

				return (char_print);
			}
	}
}
