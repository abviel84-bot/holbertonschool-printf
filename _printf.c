#include "main.h"

/**
 * handle_char - prints a character
 * @args: va_list containing the character
 * Return: number of characters printed (1)
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * handle_string - prints a string
 * @args: va_list containing the string
 * Return: number of characters printed
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		count += _putchar(str[i]);
		i++;
	}

	return (count);
}

/**
 * handle_percent - prints a percent sign
 * Return: number of characters printed (1)
 */
int handle_percent(void)
{
	return (_putchar('%'));
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			/* Si % está al final, terminar la función inmediatamente */
			if (format[i] == '\0')
			{
				va_end(args);
				return (count);
			}

			if (format[i] == 'c')
				count += handle_char(args);
			else if (format[i] == 's')
				count += handle_string(args);
			else if (format[i] == '%')
				count += handle_percent();
			else
			{
				/* Specifier desconocido: imprimir % + caracter */
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}
