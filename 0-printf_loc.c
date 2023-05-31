#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf_main - Printf function
 * @format: format
 * @a: characters
 * Return: print characters.
 */
int _printf_main(const char *format, ...)
{
	int ta, display = 0, characters_display = 0;
	int f, w, pr, s, buff_ind = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (ta = 0; format && format[ta] != '\0'; ta++)
	{
		if (format[ta] != '%')
		{
			buffer[buff_index++] = format[ta];
			if (buff_ind == BUFFER_SIZE)
				print_buffer(buffer, &buff_ind);
			characters_display++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			f = hand_f(format, &ta);
			w = hand_w(format, &ta, args);
			pr = hand_pr(format, &ta, args);
			s = hand_size(format, &ta);
			++ta;
			display = handle_print(format, &ta, args, buffer,
					f, w, pr, s);
			if (display == -1)
				return (-1);
			characters_display += display;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (characters_display);
}

/**
 * buffer_statement - diplay the statement
 * @buffer: buffer array
 * @buff_index: index at which to add next char, represents the length.
 */
void buffer_statement(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
