#include "main.h"

/**
 * main - entry point to test _printf
 */
int main(void)
{
    int len;

    len = _printf("Hello, %s!\n", "world");
    _printf("Char: %c\n", 'A');
    _printf("Percent: %%\n");
    _printf("Len: %d\n", len);  /* %d not handled, prints %d literally */
    return (0);
}
