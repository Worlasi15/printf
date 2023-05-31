#include "main.h"

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
