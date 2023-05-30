#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_str(va_list type; char buffer[];
int print_percent(va_list type; char buffer[];
int print_int(va_list type; char buffer[];
int print_binary(va_list type; char buffer[];
int _printf(const char *format, ...);
void print_buffer(char buffer, int *buff_ind);
void print_pointer(void *p);
int main(void);
void print_to_buffer(char *buffer, const char *format, ...);
void print_buffer(char *buffer);
int main(void);
int width_non_custom(const char *format, int *u, va_list list);
int flag_characters(const char *format, int *i);
int handle_con_spec(char c);
int standard_code(char ascii_code, char buffer[], int i);
int numerical_digit(char c);
int change_number(long int num, int size);

#endif
