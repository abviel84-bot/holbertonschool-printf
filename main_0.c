#include "main.h"

int main(void)
{
	_printf("Hello %s!\n", "World");
	_printf("Char: %c\n", 'A');
	_printf("Percent: %%\n");
	_printf("Unknown: %K\n");
	_printf("End percent: \n");
	_printf("%");  /* Esto no imprime nada */
	return (0);
}
