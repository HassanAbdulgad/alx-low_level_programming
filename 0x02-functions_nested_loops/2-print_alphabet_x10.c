#include "main.h"

/**
 * main - Write a function that prints 10 times the alphabet, in lowercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
void print_alphabet_x10(void);
{
	char letter;

	int i;

	i = 0;

	while(i < 10)
	{
	    letter = 'a';
	    while(letter <= 'z')
	    {
		    _putchar(letter);
		    letter++;
	    }
	    _putchar('\n');
	    i++;
	}
}
