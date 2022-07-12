#include "main.h"

/**
 * print_char - returns char as string
 * @c: The character to print
 * Return: 1.
 */
char *print_char(va_list c)
{
	char my_char;
	char *s;

	my_char = va_arg(c, int);

	if (my_char == 0)
		my_char = '\0';

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = my_char;
	s[1] = '\0';

	return (s);
}
