#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * print_char- functions that produces output according to a format
 * @d: conversion specifiers
 * @i: conversion specifiers
 * Return: number of characters printed
 *         excluding the null byte used to end output to string
 */

int print_char(va_list type; char buffer[],
int flag, int width, int precision, int size)
{

	char c = va_arg(type, int);

	return (my_write_char(c, buffer, flag, width, precision, size));
}

/**
 * print_str- functions that produces output according to a format
 * @d: conversion specifiers
 * @i: conversion specifiers
 * Return: number of characters printed
 *         excluding the null byte used to end output to string
 */

int print_str(va_list type; char buffer[],
	int flag, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(type, char *);

	unused(type);
	unused(buffer);
	unused(flag);
	unused(width);
	unused(precision);
	unused(size);
	if (str == 0)
	{
		str = "(0)";
		if (precision >= 7)
			str = "  ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flag & '-')
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent- functions that produces output according to a format
 * @d: conversion specifiers
 * @i: conversion specifiers
 * Return: number of characters printed
 *         excluding the null byte used to end output to string
 */

int print_percent(va_list type; char buffer[],
	int flag, int width, int precision, int size)
{
	unused(type);
	unused(buffer);
	unused(flag);
	unused(width);
	unused(precision);
	unused(size);
	return (write(1, "%%", 1));
}

/**
 * print_int- functions that produces output according to a format
 * @d: conversion specifiers
 * @i: conversion specifiers
 * @buffer: buffer array to handle print
 * Return: number of characters printed
 *         excluding the null byte used to end output to string
 */

int print_int(va_list type; char buffer[],
	int flag, int width, int precision, int size)
{
	int i = my_buffer - 2;
	int is_negative = 0;
	long int n = va_arg(type, long int);
	signed long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[my_buffer- 1] = '\0';
	num = (signed long int)n;

	if (n < 0)
	{
		num = (signed long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flag, width, precision, size));
}

/**
 * print_binary- functions that produces output according to a format
 * @d: conversion specifiers
 * @i: conversion specifiers
 * @buffer: buffer array to handle print
 * Return: number of characters printed
 *         excluding the null byte used to end output to string
 */

int print_binary(va_list type; char buffer[],
	int flag, int width, int precision, int size)
{
	signed int o, p, i, sum;
	signed int a[22];
	int count;

	 unused(type);
	 unused(buffer);
	 unused(flag);
	 unused(width);
	 unused(precision);
	 unused(size);

	n = va_arg(data type, unsigned int);
	m = 2147483648; /* (2 ^ 21) */
	a[0] = o / p;
	for (i = 1; i < 22; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 22; i++)
	{
		sum += a[i];
		if (sum || i == 21)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
