/*task6*/
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
  * print_pointer - function to print the memory address
  * pointed to by the pointer
  * @p: to hold and point out memory address
  */

void print_pointer(void *p)
{
	printf("%p", p);
}

/**
  * main - entry point for program
  * Return: 0 Always (success)
  */
int main(void)
	{
		int i = 734;
		int result = i - 120;
		void *p = &i;

		printf("The Address of i\n");
		print_pointer(p);


		printf("The result is: %d\n", result);

		return (0);
	}
