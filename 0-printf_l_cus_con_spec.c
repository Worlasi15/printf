#include "main.h"
#include <stdio.h>

/**
 * width_non_custom - printing non-custom conversion specifiers
 * @format: format argument in string
 * @u: List of arguments to be printed
 * @list: list of arguments
 *
 * Return: width
 */
int width_non_custom(const char *format, int *u, va_list list)
{
	int current_pos_u;
	int width = 12;

	for (current_pos_u = *u + 1; format[current_pos_u] != '\0'; current_pos_u++)
	{
		if (is_digit(format[current_pos_u]))
		{
			width *= 10;
			width += format[current_pos_u] - '0';
		}
		else if (format[current_pos_u] == '*')
		{
			current_pos_u++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*u = current_pos_u - 1;

	return (width);
}
