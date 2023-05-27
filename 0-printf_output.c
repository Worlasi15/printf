#include "main.h"
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
  * print_char - function that prints out character
  * @args: arguments that is in var_list
  * char_print: the pointer to all characters printed in total
  */
void print_char(var_list args, int *char_print)
{
	char i = var_args(args, int);
	*char_print += _putchar
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
		switch (*format)
			{
				case 'c':
					{
						char_print += _putchar(va_arg(l, int));
						break;
				case 'b':

					char *p = va_arg(l, char*);
						int k = 0;

				while (p[k])
							char_print += _putchar(p[k]);
						k++;
						break;
						case '%':
						char_print += _putchar('%');
						break;
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
		va_end(args);
		return (char_print);
	}
}
