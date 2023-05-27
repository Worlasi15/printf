#include <unistd.h>
#include <stdio.h>

/**
  * _putchar - print character to the standard output
  * @c: preffered character to print
  *
  * Return: 1 On success, -1 on error
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
