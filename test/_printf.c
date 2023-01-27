#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	int len = 0;
	char *str;
	int num;

	va_start(args, format);

	while (format[i])
	{
	if (format[i] == '%')
	{
		i++;
	switch (format[i])
	{
		case 'c':
		len += write(1, &(va_arg(args, int)), 1);
			break;
		case 's':
		str = va_arg(args, char *);
		len += write(1, str, _strlen(str));
		break;
		case '%':
		len += write(1, "%", 1);
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			len += _print_num(num);
		break;
		default:
		len += write(1, "Invalid format", 14);
			return (len);
	}
	}
	else
	{
		len += write(1, &format[i], 1);
	}
	i++;
	}

	va_end(args);
	return (len);
}

/**
 * _strlen - function that finds the length of a string
 * @s: string to find length of
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
	{
	len++;
	}

	return (len);
}

/**
 * _print_num - function that prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int _print_num(int n)
{
	int len = 0;

	if (n < 0)
	{
	len += write(1, "-", 1);
	n = -n;
	}

	if (n >= 10)
	{
	len += _print_num(n / 10);
	}

	len += write(1, &"0123456789"[n % 10], 1);

	return (len);
}
