#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf_main - Printf function
 * @format: format
 * @a: character
 * Return: print characters.
 */
int _printf_main(const char *format, ...)
{
	int ta, display = 0, characters_display = 0;
	int f, w, pr, s, buff_index = 0;
	va_list arguments;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arguments, format);

	for (ta = 0; format && format[ta] != '\0'; ta++)
	{
		if (format[ta] != '%')
		{
			buffer[buff_index++] = format[ta];
			if (buff_index == BUFFER_SIZE)
				print_buffer(buffer, &buff_index);
			characters_display++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			f = hand_f(format, &ta);
			w = hand_w(format, &ta, arguments);
			pr = hand_pr(format, &ta, arguments);
			s = hand_size(format, &ta);
			++ta;
			display = handle_print(format, &ta, arguments, buffer,
					f, w, pr, s);
			if (display == -1)
				return (-1);
			characters_display += display;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(arguments);

	return (characters_display);
}

/**
 * buffer_statement - diplay the statement
 * @buffer: buffer array
 * @buff_index: index at which to add next char, represents the length.
 */
void buffer_statement(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
