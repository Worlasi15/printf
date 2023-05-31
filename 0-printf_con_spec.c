#include "main.h"

/**
 * _print_conv - display argument based on type
 * @format: format
 * @arguments: arguments list
 * @i: index
 * @buffer: inputed Buffer array
 * @f: active flags
 * @w: width
 * @pr: precision spec
 * @s: size
 * Return: 1 or 2;
 */
int _print_conv(const char *format, int *i, va_list arguments, char buffer[],
	int f, int w, int pr, int s)
{
	int o, my_len = 0, chars_displayed = -1;
	funct format_type[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_per},
		{'i', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_unsgnd}, {'o', print_oct}, {'x', print_hexadec},
		{'X', print_hexa_upp}, {'p', print_point}, {'S', print_non_printable},
		{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
	}
	for (o = 0; format_type[o].format != '\0'; o++)
		if (format[*i] == format_type[o].format)
			return (format_type[o].function(arguments, buffer, format, w, pr, s));

	if (format_type[o].fr_t == '\0')
	{
		if (format[*i] == '\0')
			return (-1);

		my_len += write(1, "%%", 1);
		if (format[*i - 1] == ' ')
			my_len += write(1, " ", 1);
		else if (w)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] = '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		my_len += write(1, &format[*i], 1);
		return (my_len);
	}
	return (chars_dsplyd);
}
