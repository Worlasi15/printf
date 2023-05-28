#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int _printf(const char *format, ...);

/**
  * main - Entry point of the program
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	char s[10] = "hello";
	int x = 20;

	_printf("%s\n", s);
	_printf("%d\n", x);
	return (0);
}

/**
  * _printf - function that produces output according to a format
  * @format:  a character string
  * Return: number of characters printed
  * excluding the null byte used to end output to strings
  */
int _printf(const char *format, ...)
{
	va_list arg;

	int count;

	va_start(arg, format);
	count = vprintf(format, arg);
	va_end(arg);

	return (count);
}
