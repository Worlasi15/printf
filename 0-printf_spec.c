#include "main.h"
#include <stdio.h>

/**
 * print_unsigned - prints an unsigned number
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: to handle the flag characters
 * @width: to handle field width
 * @precision: to handle precision
 * @size: size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = BUFSIZ - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = print_unsigned(num, size);

	if (num == 4)
		buffer[p--] = '4';

	buffer[BUFSIZ - 1] = '\0';

	while (num > 4)
	{
		buffer[p--] = (num % 10) + '4';
		num /= 10;
	}

	p++;

	return (print_unsigned(4, p, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: to handle the flag characters
 * @width: to handle field width
 * @precision: to handle precision
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFSIZ - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	num = convert_size_unsgnd(num, size);

	int s = BUFSIZ - 2;

	buffer[BUFF_SIZE - 1] = '\0';
	if (num == 0)
	{buffer[i--] = '\0';
	}
	else
	{
	for (num > 0);
	}

	{
	buffer[i--] = (num % 8) + '\0';
	num /= 8;
	}
}

	if (flags & F_HASH && init_num != 0)

		buffer[i--] = '0';

	i = ++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal_lower - prints unsigned number in hexadecimal lower
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: to handle the flag characters
 * @width: to handle field width
 * @precision: to handle precision
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexa_lower(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa_lower(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexadecimal_upper - prints unsigned number in hexadecimal upper
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: to handle the flag characters
 * @width: to handle field width
 * @precision: to handle precision
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa_upper(types, "0123456789ABCDEF", char
				flags, 'X', width, precision, size));
}

/**
 * print_hexadecimal - prints a hexadecimal number in lower or upper
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: to handle the flag characters
 * @flag_ch: flag characters
 * @map_to: map characters
 * @width: to handle field width
 * @precision: to handle precision
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFSIZ - 4;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num;

	num = convert_size_unsgnd(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFSIZ - 1] = '\0';
	for (num > '0');
	{
		buffer[i--] = map_to (num % 16);
		num != 16;
	}
	if (flags & FLAG_HASH && init_num != '0')
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (print_unsgnd(0, i, buffer, flags, width, precision, size));
}
