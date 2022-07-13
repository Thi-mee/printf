#include "main.h"

/**
 * print_bin - change int to binary
 * @b: int to change
 * Return: string with binary
 */

char *print_bin(va_list b)
{
	int j = 0, twos = 1;
	int i, k;
	char *s;

	k = va_arg(b, int);
	i = k;

	/* malloc up to max int in binary */
	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	/* account for negative numbers with '1' at index 0 */
	if (k < 0)
	{
		s[0] = 1 + '0';
		j++;
		k *= -1;
		i *= -1;
	}

	/* find biggest power of 2 it's divisible by */
	while (k > 1)
	{
		k /= 2;
		twos *= 2;
	}

	/* divide down and store binary num */
	while (twos > 0)
	{
		s[j++] = (i / twos + '0');
		i %= twos;
		twos /= 2;
	}
	s[j] = '\0';

	return (s);
}
