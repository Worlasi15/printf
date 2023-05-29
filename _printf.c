#include <stdarg.h>
#include <unistd.h>

/**
 * print_character - Helper function to print a single character
 * @arg: The argument containing the character to print
 * @char_count: Character pointer
 */
void print_character(va_list arg, int *char_count)
{
	int c = va_arg(arg, int);

	_putchar(c);
	(*char_count)++;
}

/**
 * print_string - Helper function to print a string
 * @arg: The argument containing the string to print
 * @char_count: Character pointer
 */
void print_string(va_list arg, int *char_count)
{
	char *s = va_arg(arg, char *);

	while (*s)
	{
		_putchar(*s);
		s++;
		(*char_count)++;
	}
}

/**
 * print_default - Helper function to print a default character
 * @c: The character to print
 * @char_count: Character pointer
 */
void print_default(char c, int *char_count)
{
	_putchar(c);
	(*char_count)++;
}

/**
 * handle_format - Handle a format specifier in the format string
 * @format: The format string
 * @args: The variable arguments list
 * @char_count: Character pointer
 */
void handle_format(const char **format, va_list args, int *char_count)
{
	(*format)++;

	switch (**format)
	{
	case 'c':
		print_character(args, char_count);
		break;

	case 's':
		print_string(args, char_count);
		break;

	case '%':
		print_default('%', char_count);
		break;

	default:
		print_default('%', char_count);
		print_default(**format, char_count);
		break;
	}
}

/**
* _printf - custom function to print
 * @format: str format
 * Code by - Faith
 * Return: print char num
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int char_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			print_default(*format, &char_count);
		}
		else
		{
			handle_format(&format, args, &char_count);
		}

		format++;
	}

	va_end(args);

	return (char_count);
}
