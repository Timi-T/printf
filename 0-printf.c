#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

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
	int character_count = 0;

	if (format == 0)
	{
		return (0);
	}
	va_start(data, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			character_count++;
		}
		else
		{
			if (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == 'd')
			{
				switch(*(format + 1))
				{
					case 'c':
						character_count += print_char(va_arg(data, int));
						format++;
						break;
					case 's':
						character_count += print_string(va_arg(data, char *));
						format++;
						break;
					case '%':
						_putchar('%');
						character_count++;
						break;
					case 'd':
						character_count += print_integer(va_arg(data, int));
						format++;
						break;
				}
			}
		}
		format++;
	}
	va_end(data);
	printf("%d\n", character_count);
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

int main(void)
{
	_printf("my name is %s and i am %d years old\n", "Opeyemi", 789);
	return (0);
}
