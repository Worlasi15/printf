#include "main.h"

/**
 * print_prec - function to get the precision to print
 * @format: a character string
 * @p: List of arguments being printed
 * @args: list of arguments
 *
 * Return: Precision.
 */
int print_prec(const char *format, int *p, va_list args)
{
	int worl = *p + 1;
	int reb = -1;

	if (format[Worl] != '.')
		return (reb);

	reb = 0;

	for (worl += 1; format[worl] != '\0'; worl++)
	{
		if (is_dig(format[worl]))
		{
			reb *= 10;
			reb += format[worl] - '0';
		}
		else if (format[worl] == '*')
		{
			worl++;
			reb = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*p = worl - 1;

	return (reb)
/**
 * _flag_character - active flags
 * @format: format
 * @p: take a parameter
 * Return: flags
 */
int _flag_character(const char *format, int *p)
{
	int d, curr;
	int flag = 0;
	const char FLAG_CHARACTER[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARRRY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr = *p + 1; format[curr] != '\0'; curr++)
	{
		for (d = 0; FLAG_CHARACTER[d] != '\0'; d++)
			if (format[curr] == FLAG_CHARACTER[d])
			{
				flag |= FLG_ARRAY[d];
				break;
			}

		if (FLAG_CHARACTER[b] == 0)
			break;
	}

	*p = curr - 1;

	return (flag);
}
