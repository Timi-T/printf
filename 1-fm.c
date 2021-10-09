#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_char - function to print out a single character
 *
 * @c: character to be printed out
 *
 * Return: nothing
 */

int print_char(char c)
{
	int count = 0;

	_putchar((char) c);
	count++;
	return (count);
}

/**
 * print_string - function to print out a string of characters
 *
 * @s: string to be printed out
 *
 * Return: nothing
 */

int print_string(char *s)
{
	int count = 0;
	char *null = "(null)";

	if (s == 0)
	{
		while (*null != '\0')
		{
			_putchar(*null);
			count++;
			null++;
		}
		return (count);
	}
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * print_integer - function to print out an integer
 *
 * @i: integer to be printed out
 *
 * Return: nothing
 */

int print_integer(int i)
{
	int num2 = i;
	int a = 0, len = 0, len2 = 0;
	int temp, count = 0;

	if (i < 0)
	{
		_putchar(45);
		count++;
		num2 = i * (-1);
	}
	if (i != 0)
	{
		len = integer_length(i);
	}
	while (len != 1 && len != 0)
	{
		temp = num2;
		while (num2 >= 10)
		{
			a = num2 / 10;
			num2 = a;
			if (a < 10)
			{
				_putchar(a + 48);
				count++;
				num2 = temp - (_pow(10, (len - 1)) * a);
				len2 = integer_length(num2);
				if (len2 != len - 1)
				{
					_putchar(48);
					count++;
					len--;
				}
				len--;
				break;
			}
		}
	}
	_putchar(num2 + 48);
	count++;
	return (count);
}

/**
 * integer_length - function to get length of an integer
 *
 * @i: integer to get length of
 *
 * Return: length of integer
 */

int integer_length(int i)
{
	int c = 0, length = 0;

	while (i != 0)
	{
		c = i % 10;
		i = i - c;
		i = i / 10;
		length++;
	}
	return (length);
}
/**
 * _pow - function to raise a number to a power
 *
 * @i: base number
 * @j: power
 *
 * Return: power of base number
 */

int _pow(int i, int j)
{
	int power = 1;
	int a;

	if (j == 0)
	{
		return (1);
	}
	if (j == 1)
	{
		return (i);
	}
	for (a = j; a > 0; a--)
	{
		power *= i;
	}
	return (power);
}
