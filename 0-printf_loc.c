#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
  * print_to_buffer - function to accept a variable number of arguments
  * @format: is a character string
  * @buffer:buffer array to handle print
  * vsnprint - function used to format the arguments
  * Return: 0 Always (success)
  */

void print_to_buffer(char *buffer, const char *format, ...)
{
	va_list par;

	int remaining_space = BUFFER_SIZE - strlen(buffer) - 1;
	int chars_written = vsnprintf(buffer + strlen(buffer),
			remaining_space, format, par);


	va_start(par, format);

	va_end(par);

	if (chars_written >= remaining_space)
	{
		printf("%s", buffer);
		buffer[0] = '\0';
		print_to_buffer(buffer, format, par);
	}
}
/**
  * print_buffer - function to print content in the buffer
  * @buffer: buffer containing the data to be printed
  */

void print_buffer(char *buffer)
{
	printf("%s", buffer);

	buffer[0] = '\0';
}

/**
  * main - the entry point of the program
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	char buffer[BUFFER_SIZE];

	buffer[0] = '\0';
	print_to_buffer(buffer, "Rebecca is my, %s!\n", "collaborator");
	print_to_buffer(buffer, "This is a test: %d\n", 42);
	print_to_buffer(buffer, "next message: %f\n", 6.14);

	print_buffer(buffer);

	return (0);
}
