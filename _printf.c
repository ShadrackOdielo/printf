#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
  * _printf - produces output according to a format.
  * @format: a character string.
  * Return: number of characters printed(
  * excluding the null terminator)
  */

int _printf(const char *format, ...)
{
	int count;
	int total = 0;
	va_list args;
	int flag = 0;

	if (format == NULL)
		return (0);

	va_start(args, format);
	for (count = 0; *(format + count) != '\0'; count++)
	{
		if (format[count] == '%')
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
			total += handle_format_specifiers(format[count], args);
		}
		else
		{
			_putchar(format[count]);
			total += 1;
		}
	}
	va_end(args);
	return (total);
}

/**
  * handle_format_specifiers - handles format specifiers
  * @specifier: format specifier
  * @args: list of arguments
  * Return: number of characters printed
  */
int handle_format_specifiers(const char specifier, va_list args)
{
switch (specifier)
	{
	case 'c':
		_putchar(va_arg(args, int));
		return (1);
	case 's':
		return (_print_str(va_arg(args, char *)));
	case '%':
		_putchar('%');
		return (1);
	case 'd':
		return (_print_int((long)(va_arg(args, int))));
	case 'i':
		return (_print_int((long)(va_arg(args, int))));
	case 'b':
		return (to_Binary(va_arg(args, int)));
	case 'u':
		return (_print_int(va_arg(args, unsigned int)));
	case 'o':
		return (to_Octal(va_arg(args, int)));
	case 'x':
		return (to_Hexa(va_arg(args, int)));
	case 'X':
		return (to_Hexa(va_arg(args, int)));
	case 'p':
		return (print_address(args));
	default:
		_putchar('%');
		_putchar(specifier);
return (2);
}
}
