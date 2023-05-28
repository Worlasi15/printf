#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#include <unistd.h>
#include <stdio.h>
/**
 * _putchar - print character to the standard output
 * @c: preffered character to print
 ** Return: 1 On success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _printf - function that produces output according to a format
  * @format: a character string
  * Return:  number of characters printed
  * excluding the null byte used to end output to strings
  */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(l, format);

	int char_print = 0;

	while (*format)
	{

		if (*format == '%')
		{
			format++;

			if (*format == 'b')
			{
				unsigned int par = va_arg(l, unsigned int);
				int bit_count = sizeof(par) * 8;

				for (int i = bit_count - 1; i >= 0; i--)
				{

					char_print += _putchar((par & (1 << i)) ? '1' : '0');
				}
			}
			else
			{
				char_print += _putchar('%');
				char_print += _putchar(*format);
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

