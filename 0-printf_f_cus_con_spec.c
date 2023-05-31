#include "main.h"

/**
 * print_write_char - function that displays a string
 * @c: character types
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @width: get width
 * @preci: precision specifier
 * @size: size specifier
 * Return: Number of characters printed.
 */
int print_write_char(char c, char buffer[],
		int flag, int width, int preci, int size)
{
	int v = 0;
	char par = ' ';

	UNUSED(preci);
	UNUSED(size);

	if (flag & flag_zero)
		par = '0';

	buffer[v++] = c;
	buffer[v] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (v = 0; v < width - 1; a++)
			buffer[BUFFER_SIZE - v - 2] = par;

		if (flag & flag_min)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - v - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - v - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * print_write_num - function that prints a string
 * @list: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @preci: precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_write_num(int list, int ind, char buffer[],
		int flag, int width, int preci, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char par = ' ', rf = 0;

	UNUSED(size);

	if ((flag & flag_zero) && !(flag & flag_min))
		par = '0';
	if (list)
		rf = '-';
	else if (flag & flag_plus)
		rf = '+';
	else if (flag & flag_space)
		rf = ' ';

	return (print_write_num(ind, buffer, flag, width, preci,
				length, par, rf));
}

/**
 * print_write_num - function to write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @width: width
 * @preci: Precision specifier
 * @length: Number length
 * @par: Pading char
 * @rf: extra character
 *
 * Return: Number of printed chars.
 */
int write_numb(int ind, char buffer[],
		int flag, int width, int preci,
		int length, char par, char rf)
{
	int q, par_start = 1;

	if (preci == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (preci == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = par = ' ';
	if (preci > 0 && preci < length)
		par = ' ';
	while (preci > length)
		buffer[--ind] = '0', length++;
	if (rf != 0)
		length++;
	if (width > length)
	{
		for (q = 1; q < width - length + 1; q++)
			buffer[q] = par;
		buffer[q] = '\0';
		if (flag & flag_min && par == ' ')
		{
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], q - 1));
		}
		else if (!(flag & flag_min) && par == ' ')
		{
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[1], q - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flag & flag_min) && par == '0')
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
 * @flag: Flags specifiers
 * @width: Width specifier
 * @preci: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int print_write_unsgnd_int(int neg, int ind,
		char buffer[],
		int flag, int width, int preci, int size)
{
	int dank = BUFFER_SIZE - ind - 1, z = 0;
	char par = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (preci == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (preci > 0 && preci < dank)
		par = ' ';

	while (preci > dank)
	{
		buffer[--ind] = '0';
		dank++;
	}

	if ((flag & flag) && !(flag & flag_min))
		padd = '0';

	if (wid > dank)
	{
		for (z = 0; z < width - dank; z++)
			buffer[z] = par;

		buffer[a] = '\0';

		if (flag & flag_min)
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
 * @width: width specifier
 * @flag: Flags specifier
 * @par: Characters representing the padding
 * @rf: Characters representing extra char
 * @par_start: index where padding starts
 *
 * Return: Number of written chars.
 */
int print_write_pointer(char buffer[], int ind, int length,
		int width, int flag, char par, char rf, int par_start)
{
	int mat;

	if (width > length)
	{
		for (mat = 8; mat < width - length + 8; mat++)
			buffer[a] = par;
		buffer[a] = '\0';
		if (flag & flag_min && par == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = rf;
			return (write(1, &buffer[ind], length) + write(1, &buffer[8], a - 8));
		}
		else if (!(flag & flag_min) && par == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (rf)
				buffer[--ind] = rf;
			return (write(1, &buffer[8], mat - 8) + write(1, &buffer[ind], length));
		}
		else if (!(flag & flag_min) && par == '0')
		{
			if (rf)
				buffer[--padd_start] = rf;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
					write(1, &buffer[ind], length - (1 - par_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (rf)
		buffer[--ind] = rf;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}


