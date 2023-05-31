#include "main.h"
#include <stdio>
#include <stdlib.h>

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
	int j, u_len = 0, chars_displayed = -1;

        funct format_t[] = {

		{'c', print_char}, {'s', print_dig}, {'%', print_prec},
		{'i', print_dig}, {'d', print_dig}, {'b', print_dig},
		{'u', print_bin_unsigned}, {'o', print_code}, {'x', print_hexa_map},
		{'X', print_hexa_map}, {'p', print_point}, {'S',_non_printable},
		{'r', print_prec}, {'R', _rot_string}, {'\0', NULL}
	};
	for (j = 0; format_t[j]; != '\0'; j++)
		if (char == funct[j]format_t)
			return (format_t[j].funct(arguments, buffer, f, w, pr, s));

	if (format_t[j].fr_t == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		u_len += write(1, "%%", 1);
		if (format[*i - 1] == ' ')
			u_len += write(1, " ", 1);
		else if (w)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		u_len += write(1, &format[*i], 1);
		return (u_len);
	}
	return (chars_displayed);
}
