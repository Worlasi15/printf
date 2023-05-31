#include "main.h"

/**
 * print_write_char - function that displays a string
 * @c: character types
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags.
 * @w: get width
 * @pr: precision specifier
 * @s: size specifier
 * Return: Number of characters printed.
 */
int print_write_char(char c, char buffer[],
		int f, int w, int pr, int s)
{
	int v = 0;
	char par = ' ';

	UNUSED(pr);
	UNUSED(s);

	if (flag & FLAG_ZERO)
		par = '0';

	buffer[v++] = c;
	buffer[v] = '\0';

	if (w > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (v = 0; v < w - 1; v++)
			buffer[BUFFER_SIZE - v - 2] = par;

		if (flag & FLAG_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - v - 1], w - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - v - 1], w - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * print_write_num - function that prints a string
 * @list: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @pr: precision specifier
 * @s: Size specifier
 * Return: Number of characters printed.
 */
int print_write_num(int list, int ind, char buffer[],
		int f, int w, int pr, int s)
{
	int length = BUFFER_SIZE - ind - 1;
	char par = ' ', rf = 0;

	UNUSED(s);

	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
		par = '0';
	if (list)
		rf = '-';
	else if (f & FLAG_PLUS)
		rf = '+';
	else if (f & F_SPACE)
		rf = ' ';

	return (print_write_num(ind, buffer, f, w, pr,
				length, par, rf));
}

/**
 * print_write_num - function to write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @f: Flags
 * @w: width
 * @pr: Precision specifier
 * @length: Number length
 * @par: Pading char
 * @rf: extra character
 *
 * Return: Number of printed chars.
 */
int write_numb(int ind, char buffer[],
		int f, int w, int p,
		int length, char par, char rf)
{
	int q, par_start = 1;

	if (pr == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && w == 0)
		return (0);
	if (pr == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = par = ' ';
	if (pr > 0 && pr < length)
		par = ' ';
	while (pr > length)
		buffer[--ind] = '0', length++;
	if (rf != 0)
		length++;
	if (w > length)
	{
		for (q = 1; q < w - length + 1; q++)
			buffer[q] = par;
		buffer[q] = '\0';
		if (f & FLAG_MINUS && par == ' ')
		{
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], q - 1));
		}
		else if (!(f & FLAG_MINUS) && par == ' ')
		{
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[1], q - 1) + write(1, &buffer[ind], length));
		}
		else if (!(f & FLAG_MINUS) && par == '0')
		{
			if (rf)
				buffer[--par_start] = rf;
			return (write(1, &buffer[par_start], q - par_start) +
					write(1, &buffer[ind], length - (1 - par_start)));
		}
	}
	if (rf)
		buffer[--ind] = rf;
	return (write(1, &buffer[ind], length));
}

/**
 * print_write_unsgnd_int - function to write an unsigned number
 * @neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @f: Flags specifiers
 * @w: Width specifier
 * @pr: Precision specifier
 * @s: Size specifier
 * Return: Number of written chars.
 */
int print_write_unsgnd_int(int neg, int ind,
		char buffer[],
		int f, int w, int pr, int s)
{
	int dank = BUFFER_SIZE - ind - 1, z = 0;
	char par = ' ';

	UNUSED(neg);
	UNUSED(s);

	if (pr == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (pr > 0 && pr < dank)
		par = ' ';

	while (pr > dank)
	{
		buffer[--ind] = '0';
		dank++;
	}

	if ((f & f) && !(f & FLAG_MINUS))
		par = '0';

	if (w > dank)
	{
		for (z = 0; z < w - dank; z++)
			buffer[z] = par;

		buffer[z] = '\0';

		if (f & FLAG_MINUS)
		{
			return (write(1, &buffer[ind], dank) + write(1, &buffer[0], z));
		}
		else
		{
			return (write(1, &buffer[0], z) + write(1, &buffer[ind], dank));
		}
	}

	return (write(1, &buffer[ind], dank));
}

/**
 * print_write_pointer - function that writes a memory address
 * @buffer: Arrays of characters
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @w: width specifier
 * @f: Flags specifier
 * @par: Characters representing the padding
 * @rf: Characters representing extra char
 * @par_start: index where padding starts
 *
 * Return: Number of written chars.
 */
int print_write_pointer(char buffer[], int ind, int length,
		int w, int f, char par, char rf, int par_start)
{
	int mat;

	if (w > length)
	{
		for (mat = 8; mat < w - length + 8; mat++)
			buffer[mat] = par;
		buffer[mat] = '\0';
		if (f & FLAG_MINUS && par == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[ind], length) + write(1, &buffer[8], mat - 8));
		}
		else if (!(f & FLAG_MINUS) && par == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[8], mat - 8) + write(1, &buffer[ind], length));
		}
		else if (!(flag & FLAG_MINUS) && par == '0')
		{
			if (rf)
				buffer[--par_start] = rf;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[par_start], mat - par_start) +
					write(1, &buffer[ind], length - (1 - par_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (rf)
		buffer[--ind] = rf;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}


