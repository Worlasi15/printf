#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_ZERO (1 << 2)
#define F_HASH (1 << 3)
#define F_SPACE (1 << 4)

/* SIZES */
#define long_num (1 << 0)
#define short_num (1 << 1)

/**
 * struct frt - Struct op
 * @frt: The format.
 * @fun: The function associated with the format.
 */
struct frt
{
	char frt;
	int (*fun)(va_list, char[], int, int, int, int);
};

/**
 * struct funct - Struct op
 * @fr_t: The format.
 * @funct: The function associated.
 */
typedef struct funct
{
	char fr_t;
	int (*funct)(va_list, char[], int, int, int, int);
} funct;

/** prtotypes */
int _printf(const char *format, ...);
int print_prec(const char *format, int *p, va_list args);
int print_size(const char *format, int *p);
int print_char(char k);
int print_append_hexa(char ascii, char buffer[], int l);
int print_dig(char m);
long int print_num_size_con(long int dig, int size);
long int print_conv_size(unsigned long int num, int size);
int print_write_char(char c, char buffer[],
int flag, int width, int preci, int size);
int print_write_num(int list, int ind, char buffer[], int flag,
int width, int preci, int size);
int print_write_unsgnd_int(int neg, int ind, char buffer[],
int flag, int width, int preci, int size);
int print_write_pointer(char buffer[], int ind, int length,
int flag, int width, int size);
int character_print_(va_list type, char buffer[]);
int _string(va_list t, char buffer[]);
int precision_per(va_list t, char buffer[]);
int _print_integer(va_list t, char buffer[]);
int print_bin_unsigned(va_list t, char buffer[]);
int _unsigned_num_print(va_list t, char buffer[]);
int print_oct_notation(va_list t, char buffer[]);
int print_hexa_lower_case(va_list t, char buffer[]);
int print_hexa_upper_case(va_list t, char buffer[]);
int print_hexa_map(va_list t, char map[], char buffer[]);
int _pointer_(va_list t, char buffer[]);
int _print_code_(va_list t, char buffer[]);
int _reverse(va_list t, char buffer[]);
int _rot_string(va_list t, char buffer[]);
void print_buffer(char buffer[], int *buff_ind);
int _printf_main(const char *format, ...);
void buffer_statement(char buffer[], int *buff_index);
int _flag_character(const char *format, int *p);
int _print_conv(const char *format, int *i, va_list arguments, char buffer[]);

#endif

