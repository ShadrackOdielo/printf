#ifndef MAIN_H
#define MAIN_H
#define NULL ((void *)0)
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);
int _print_str(char *string);
int _print_int(long int var);
int _printf(const char *format, ...);
int to_Binary(unsigned int n);
int to_Octal(unsigned int n);
int _power_recursion(int x, int y);
int to_Hexa(unsigned int num);
int handle_format_specifiers(const char specifier, va_list args);
int print_address(va_list args);

#endif
