#include "main.h"

/**
 * print_char - checks the characted to be printed
 * @k: inputed character.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int print_char(char k)
{
	if (k >= 32 && k < 127)
		return (1);

	return (0);
}

/**
 * print_append_hexa - function to append ascii to buffer
 * @buffer: Array of characters
 * @l: the index appending starts at
 * @ascii: ASCII CODE
 * Return: 3 Always (success)
 */
int print_append_hexa(char ascii, char buffer[], int l)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[l++] = '\\';
	buffer[l++] = 'l';

	buffer[l++] = map[ascii / 16];
	buffer[l] = map[ascii % 16];

	return (3);
}

/**
 * print_dig - checks digit as a character
 * @m: character that is inputted
 *
 * Return: 1 if c is a digit, else 0
 */
int print_dig(char m)
{
	if (m >= '0' && m <= '9')
		return (1);

	return (0);
}

/**
 * print_num_size_con - the specified size of a number is casted
 * @dig: number that was inputted
 * @size: Number indicating the type to be casted.
 *
 * Return: casted value of dig
 */
long int print_num_size_con(long int dig, int size)
{
	if (size == long_num)
		return (dig);
	else if (size == short_num)
		return ((short)dig);

	return ((int)dig);
}

/**
 * print_conv_size - function that casts a number to the specified size
 * @numeral: the number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: casted value of numeral
 */
long int print_conv_size(unsigned long int numeral, int size)
{
	if (size == long_num)
		return (numeral);
	else if (size == short_num)
		return ((unsigned short)numeral);

	return ((unsigned int)numeral);
}

