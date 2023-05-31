#include "main.h"
/**
 * print_width - the width for display is calculated.
 * @format: a character string
 * @p: list of arguments
 * @args: list of arguments
 * Return: width
 */
int print_width(const char *format, int *p, va_list args)
{
	int becfat;
	int w = 0;

	for (becfat = *p + 1; format[becfat] != '\0'; becfat++)
	{
		if (print_dig(format[becfat]))
		{
			w *= 10;
			w += format[becfat] - '0';
		}
		else if (format[becfat] == '*')
		{
			becfat++;
			w = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*p = becfat - 1;

	return (w);
}
