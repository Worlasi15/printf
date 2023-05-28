#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void print_buffer(char buffer, int *B_I);
/**
  * _printf - function that produces output according to a format
  * @format:  a character string
  * Return: number of characters printed
  * excluding the null byte used to end output to strings
  */
int _printf(const char *format, ...)
{
	int k = 0;
	printed = 0;
	char_print = 0;
	int flag = 0;
	int width = 0;
	int precision = 0;
	int size = 0;
	int B_I = 0;
	va_list par;
	char buffer [BUFF_SIZE];


	if (format ==NULL)
		return (-1);

	va_start(par, format);

	for (i = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[B_I++] = format[k];

			if (B_I == BUFF_SIZE)
				print_buffer(buffer, &B_I);
		}
		else
		{
			print_buffer(buffer, &B_I);
			flags = get_flag(format, &k);
			precision = get_precision(format, &k, par);
			width = get_width(format, &k, par);
			size = get_size(format, &k);
			++k;
			printed = handle_print(format, &k, par, flags, size, width, buffer, precision);

			if (printed == -1)
				char_print += printed;
		}
	}

	print_buffer(buffer, &B_I);

	va_end(par);

	return (char_print);
}
/**
 * print_buffer - function to print buffer content
 * @buffer: an array of characters
 * @B_I: the index to add to next character
 */
void print_buffer(char buffer, int *buff_ind);
{
	if (*B_I > 0)
		write(1, &buffer[0], *B_I);
	*B_I = 0;
}
