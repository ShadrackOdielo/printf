#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf_string(va_list args);
int _printf_percent(void);
int _printf_char(va_list args);
size_t _strlen(const char *s);

/**
* _printf - function that produces output according to a format
* @format: character string
*
* Return: number of characters printed
*/


int _printf(const char *format, ...)
{
	int chars_written = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
	if (*format == '%')
	{
		format++;
	switch (*format)
	{
		case 'c':
		chars_written += _printf_char(args);
			break;
		case 's':
			chars_written += _printf_string(args);
		break;
		case '%':
		chars_written += _printf_percent();
			break;
		default:
			chars_written += write(1, format, 1);
		}
	} else
	{
		chars_written += write(1, format, 1);
	}
	format++;
	}

	va_end(args);
	return (chars_written);
}

/**
* _printf_percent - function that produces output according to a format
* Return: number of characters printed
*/


int _printf_percent(void)
{
	char c = '%';

	return (write(1, &c, 1));
}

/**
* _printf_string - function that produces output according to a format
* @args:the arguments.
* Return: number of characters printed
*/


int _printf_string(va_list args)
{
	char *str = va_arg(args, char*);

	return (write(1, str, _strlen(str)));
}

/**
* _strlen - function that produces output according to a format
*@s:character pointer.
* Return: number of characters printed
*/

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
	len++;
}
	return (len);
}

/**
* _printf_char - function that produces output according to a format
*@args:the args here.
* Return: number of characters printed
*/

int _printf_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
