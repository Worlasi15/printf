#include "main.h"

/**
 * _unsigned_num_print - print an unsigned number
 * @t: type arguments list
 * @buffer: buffer array
 * @f: active flags
 * @w: width
 * @pr: precision spec
 * @s: size specifier
 * Return: number of chars displayed.
 */
int _unsigned_num_print(va_list t, char buffer[],
		int f, int w, int pr, int s)
{
	int x = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;
	return (write_unsigned(0, x, buffer, f, w, pr, s));
}

/**
 * print_oct_notation - displays an unsigned number in octal notation
 * @t: type arguments list
 * @buffer: buffer array
 * @f: active flags
 * @w: width
 * @pr: precision spec
 * @s: size specifier
 * Return: number of characters displayed
 */
int print_oct_notation(va_list t, char buffer[],
		int f, int w, int pr, int s)
{

	int c = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		buffer[c--] = '0';

	c++;
	return (write_unsgnd(0, c, buffer, f, w, pr, s));
}

/**
 * print_hexa_lower_case - prints unsigned number in hexadecimal
 * @t: type arguments list
 * @buffer: buffer array to handle print
 * @f: active flags
 * @w: width
 * @pr: precision spec
 * @s: size specifier
 * Return: number of characters printed
 */
int print_hexa_lower_case(va_list t, char buffer[],
		int f, int w, int pr, int s)
{
	return (print_hexa_map(t, "0123456789abcdef", buffer,
				f, 'x', w, pr, s));
}

/**
 * print_hexa_upper_case - prints an unsigned number in upper hexadecimal
 * @t: type of arguments list
 * @buffer: buffer array to handle print
 * @f: active flags
 * @w: width
 * @pr: precision specification
 * @s: Size specifier
 * Return: number of characters printed
 */
int print_hexa_upper_case(va_list t, char buffer[],
		int f, int w, int pr, int s)
{
	return (print_hexa_map(t, "0123456789ABCDEF", buffer,
				f, 'X', w, pr, s));
}

/**
 * print_hexa_map - Prints a hexadecimal number in lower or upper
 * @t: arguments list
 * @map: Array of values to be mapped to
 * @buffer: inputed Buffer array
 * @f: active flags
 * @f_ch: Calculates active flags
 * @w: width
 * @pr: precision spec
 * @s: Size specification
 * Return: number of characters displayed
 */
int print_hexa_map(va_list t, char map[], char buffer[],
		int f, char f_ch, int w, int pr, int s)
{
	int c = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = map[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		buffer[c--] = f_ch;
		buffer[c--] = '0';
	}

	c++;
	return (write_unsgnd(0, c, buffer, f, w, pr, s));
}
