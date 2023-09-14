#include "main.h"

/**
 * print_ alphabet - print all alphabet in lowercase
 *
 *print: new line 
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z' ; c++)
		_putchar(c);
	_putchar('\n');
}
