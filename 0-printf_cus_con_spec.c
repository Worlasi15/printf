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

	return (reb);
}

