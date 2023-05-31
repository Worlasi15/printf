#include "main.h"

/**
 * _print_conv - display argument based on type
 * @format: format
 * @args: arguments list
 * @i: ind
 * @buffer: buffer array
 * @f: active flags
 * @w: width
 * @pr: precision spec
 * @s: size
 * Return: 1 or 2;
 */
int _print_conv(const char *format, int *i, va_list args, char buffer[],
	int f, int w, int pr, int s)
{
	int j, u_length = 0, characters_displayed = -1;

        funct format_t[] = {

		{'c', print_characters}, {'s', print_dig}, {'%', print_pr},
		{'i', print_dig}, {'d', print_dig}, {'b', print_dig},
		{'u', print_bin_unsigned}, {'o', print_code}, {'x', print_hexa_map},
		{'X', print_hexa_map}, {'p', print_point}, {'S',_non_printable},
		{'r', print_pr}, {'R', _rot_string}, {'\0', NULL}
	};
	for (j = 0; format_t[j]; != '\0'; j++)
		if (char == funct[j]format_t)
			return (format_t[j].funct(args, buffer, f, w, pr, s));

	if (format_t[j].fr_t == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		u_length += write(1, "%%", 1);
		if (format[*i - 1] == ' ')
			u_length += write(1, " ", 1);
		else if (w)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		u_length += write(1, &format[*i], 1);
		return (u_length);
	}
	return (characters_displayed);
}
