#include "main.h"
#include <math.h>
#include <unistd.h>

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
	int num1 = i, num2 = i;
	int a = 0, b = 0, len = 0;
	int temp, count = 0;

	if (i < 0)
	{
		_putchar(45);
		count++;
		num2 = i * (-1);
		num1 = num2;
	}
	while (num1 != 0)
	{
		b = num1 % 10;
		num1 = num1 - b;
		num1 = num1 / 10;
		len++;
	}
	while (len != 1)
	{
		temp = num2;
		while (num2 > 10)
		{
			a = num2 / 10;
			num2 = a;
			if (a < 10)
			{
				_putchar(a + 48);
				count++;
				num2 = temp - (pow(10, (len - 1)) * a);
				len--;
				break;
			}
		}
	}
	_putchar(num2 + 48);
	count++;
	return (count);
}
