#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * character_print_ - printed display character
 * @t: type arguments list
 * @buffer: buffer array print
 * @f: active flags
 * @w: active width
 * @pr: precision spec
 * @s: size specifier
 * Return: number of characters displayed
 */
int character_print_(va_list t, char buffer[],
	int f, int w, int pr, int s)
{
	char o = va_arg(t, int);

	return (print_char(o, buffer, f, w, pr, s));
}
/**
 * _string - printed display string
 * @t: type arguments list
 * @buffer: buffer array
 * @f: active flags
 * @w: width
 * @pr: precision spec
 * @s: size specifier
 * Return: number of chars displayed
 */
int _string(va_list t, char buffer[],
		int f, int w, int pr, int s)
{
	int len = 0, i;
	char *fr = va_arg(t, char *);

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);
	if (fr == NULL)
	{
		fr = "(null)";
		if (s >= 6)
			fr = "      ";
	}

	while (fr[len] != '\0')
		len++;

	if (s >= 0 && s < len)
		len = s;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &fr[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &fr[0], len);
			return (w);
		}
	}

	return (write(1, s, len));
}

/**
 * precision_per - prints a percent sign
 * @t: type arguments list
 * @buffer: inputed buffer array
 * @f: active flags
 * @w: width
 * @pr: precision specification
 * @s: Size specifier
 * Return: number of chars displayed
 */
int precision_per(va_list t, char buffer[],
	int f, int w, int pr, int s)
{
	UNUSED(t);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);
	return (write(1, "%%", 1));
}
/**
 * _print_integer - print an integer
 * @t: type arguments list
 * @buffer: buffer array
 * @f: active flags
 * @w: width
 * @pr: Precision specification
 * @s: size specifier
 * Return: number of chars displayed
 */
int _print_integer(va_list t, char buffer[],
	int f, int w, int pr, int s)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(t, long int);
	unsigned long int num;

	n = conv_size_num(n, s);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_num(is_negative, i, buffer, f, w, pr, s));

}

/**
 * print_bin_unsigned - prints an unsigned number
 * @t: type of arguments list
 * @buffer: buffer array
 * @f: active flags
 * @w: width.
 * @pr: precision specification
 * @s: size specifier
 * Return: numbers of char displayed.
 */
int print_bin_unsigned(va_list t, char buffer[],
	int f, int w, int pr, int s)
{
	unsigned int r, k, a, sum;
	unsigned int i[32];
	int count;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);

	r = va_arg(t, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	i[0] = r / k;
	for (a = 1; a < 32; a++)
	{
		k /= 2;
		i[a] = (r / k) % 2;
	}
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum += i[a];
		if (sum || a == 31)
		{
			char z = '0' + i[a];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
