#include "main.h"
#include <stdio.h>

/**
 * _uitos - makes an int a string
 * @div: multiple of 10
 * @length: length of number
 * @n: number to convert to string
 * Return: string
 **/
char *_uitos(int div, int length, int n)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * length + 2);
	if (str == NULL)
		return (NULL);

	if (n < 0) /* account for negative sign */
	{
		str[0] = '-';
		i++;
	}
	while (n < 0) /* convert each num to string */
	{
		str[i] = ((n / div) * -1 + '0'); /* *-1 to handle min int */
		n = n % div;
		div /= 10;
		i++;
	}
	while (div >= 1) /* same, this case for positives */
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * _abs - function that computes the absolute value of an integer
 * @a: integer we'r converting
 * Return: Absolute value(can be any integer)
 */
unsigned int _abs(unsigned int a)
{
	if (a > 0 || a == 0)
		return (a);
	else
		return (a * -1);
}

/**
 * print_unsig - gets length to put in _uitos
 * @d: takes arg
 * Return: integar string
 **/
char *print_unsig(va_list u)
{
	unsigned int length, div, n, temp;

	n = va_arg(u, unsigned int);
    printf("First check => %i\n", n);
    n = _abs(n);
    printf("second check => %i\n", n);
	temp = n;
	length = 0;
	div = 1;

	if (n == 0) /* account for 0 having length 1 */
	{
		length++;
		return (_uitos(div, length, n));
	}

	while (temp != 0) /* find multiple of ten to divide */
	{
		length += 1;
		if (length > 1)
			div *= 10;
		temp /= 10;
	}

	return (_uitos(div, length, n));
}
