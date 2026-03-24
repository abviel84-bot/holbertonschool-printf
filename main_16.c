#include "main.h"

/**
 * main - test _printf for Task 0
 *
 * Return: 0
 */
int main(void)
{
	/* Prueba de string normal */
	_printf("Hello %s!\n", "World");

	/* Prueba de caracter */
	_printf("Char: %c\n", 'A');

	/* Prueba de percent */
	_printf("Percent: %%\n");

	/* Prueba de specifier desconocido */
	_printf("Unknown: %K\n");

	/* Prueba de percent al final del string */
	_printf("End percent: %\n");

	/* Prueba solo de percent al final */
	_printf("%");

	return (0);
}
