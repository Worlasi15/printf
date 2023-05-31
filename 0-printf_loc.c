#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf_main - Printf function
 * @format: format
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

	for (a = 0; format && format[z] != '\0'; z++)
	{
		if (format[z] != '%')
		{
			buffer[buff_index++] = format[z];
			if (buff_index == BUFFER_SIZE)
				print_buffer(buffer, &buff_index);
			chars_dsplyd++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			f = hand_f(format, &z);
			w = hand_w(format, &z, arguments);
			pr = hand_pr(format, &z, arguments);
			size = hand_size(format, &z);
			++z;
			dsplyd = handle_print(format, &z, arguments, buffer,
					f, w, pr, s);
			if (dsplyd == -1)
				return (-1);
			chars_dsplyd += dsplyd;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(arguments);

	return (chars_dsplyd);
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
