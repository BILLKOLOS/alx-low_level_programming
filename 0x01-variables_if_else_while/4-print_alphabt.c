#include <stdio.h>
#include <stdlib.h>
/**
 * main - returns alphabets both except e and q
 *
 * Return: Always 0 (Success)
 */
int main(void)

{
	char letter = 'a';

	while (letter <= 'z')
	char ch = 'a';

	while (ch <= 'z')
	{
		if ((letter != 'q') && (letter != 'e'))
		if ((ch != 'e') && (ch != 'q'))
		{
			putchar(letter);
			putchar(ch);
		}
		letter++;
		ch++;
	}

	putchar('\n');

	return (0);
}
