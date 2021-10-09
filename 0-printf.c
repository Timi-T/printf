#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - function to print to standard output
 *
 * @format: the string containing the format specifier
 *
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	va_list(data);
	const char *f = format;
	int character_count = 0;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(data, format);
	while (*f != '\0')
	{
		if (*f != '%')
		{
			_putchar(*f);
			character_count++;
		}
		else
		{
			f++;
			switch (*f)
			{
				case 'c':
					character_count += print_char(va_arg(data, int));
					break;
				case 's':
					character_count += print_string(va_arg(data, char *));
					break;
				case '%':
					_putchar(37);
					character_count++;
					break;
				case 'd':
					print_integer(va_arg(data, int));
					break;
				case 'i':
					print_integer(va_arg(data, int));
					break;
				case '\0':
					return (-1);
				default:
					_putchar(*f);
			}
		
		}
		f++;
	}
	va_end(data);
	return (character_count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
