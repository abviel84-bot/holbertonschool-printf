#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - prints a single character
 * @args: va_list with the char argument
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list with the string argument
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
		str = "(null)";

	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

/**
 * print_int - prints a signed integer
 * @args: va_list with the int argument
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	char digit;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = (unsigned int)(-(n + 1)) + 1;
	}
	else
		num = (unsigned int)n;

	if (num / 10)
		count += print_unsigned(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}

int print_unsigned(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 10)
		count += print_unsigned(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}
