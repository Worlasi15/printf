#include "main.h"
#include <stdio.h>

/**
 * flag_characters - characters for non-custom conversion specifiers
 * @format: format string to print
 * @i: Current index in the format string
 *
 * Return: Active flags characters
 */
int flag_characters(const char *format, int *i)
{
	const char flags_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_arr[] = {f("-"), f("+"), f(0), f("#"), f(" "), 0};

	int flags = 0;
	int curr_i = *i + 1;
	int k;

	while (format[curr_i] != '\0')
	{
		for (k = 0; flags_ch[k] != '\0'; k++)
		{
			if (format[curr_i] == flags_ch[k])
			{
				flags |= flags_arr[k];
				break;
			}
		}

		if (flags_ch[k] == '\0')
		{
			break;
		}

		curr_i++;
	}

	*i = curr_i - 1;

	return (flags);
}
