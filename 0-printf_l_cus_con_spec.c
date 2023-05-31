#include "main.h"

/**
 * print_size - determines the size of the argument
 * @format:  a character string
 * @p:the list of arguments to print
 *
 * Return: size
 */
int print_size(const char *format, int *p)
{
	int i = *p + 1;
	int size = 0;

	if (format[i] == 'l')
		size = long_num;
	else if (format[i] == 'h')
		size = short_num;

	if (size == 0)
		*p = i - 1;
	else
		*p = i;

	return (size);
}

