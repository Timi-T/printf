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

	if (format == 0)
	{
		return (0);
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
			if (*(f + 1) == 'c' || *(f + 1) == 's' || *(f + 1) == 'd')
			{
				switch (*(f + 1))
				{
					case 'c':
						character_count += print_char(va_arg(data, int));
						f++;
						break;
					case 's':
						character_count += print_string(va_arg(data, char *));
						f++;
						break;
					case '%':
						_putchar('%');
						character_count++;
						f++;
						break;
					case 'd':
						character_count += print_integer(va_arg(data, int));
						f++;
						break;
				}
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

int main(void)
{
	_printf("my name is %s and i am %d years old\n", "Opeyemi", 789);
	_printf("");
	return (0);
}