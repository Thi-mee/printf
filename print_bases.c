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


/**
 * print_octal - change int to octal
 * @o: int to change
 * Return: string with octal
 */
char *print_octal(va_list o)
{
	long j = 0, eights = 1;
	long i, k;
	char *s;

	k = va_arg(o, long);
	i = k;

	/* malloc up to max int in octal*/
	s = malloc(sizeof(char) * 12);
	if (s == NULL)
		return (NULL);

	if (k < 0)
	{
		s[0] = 1 + '0';
		j++;
		k *= -1;
		i *= -1;
	}

	/* find biggest power of 8 it's divisible by */
	while (k > 1)
	{
		k /= 8;
		eights *= 8;
	}

	/* divide down and store octal num */
	while (eights > 0)
	{
		s[j++] = (i / eights + '0');
		i %= eights;
		eights /= 8;
	}
	s[j] = '\0';

	return (s);
}


/**
 * recurse - recursively creates string
 * @x: integer
 * Return: A string pointer
 */
char *recurse(unsigned int num, int size)
{
    unsigned int rem;
    char *str;
    char temp;
    int i, j;

    i = 0;
    j = 0;
    rem = num % 16;
    i++;

    if (num / 16 == 0)
    {
        str = malloc((sizeof(char) * i) + 2);
        if (rem < 10)
            temp = 48 + rem;
        else if (rem >= 10 && size == 0)
            temp = 87 + rem;
        else
            temp = 55 + rem;
        *(str + j) = temp;
        return (str);
    }
    str = recurse(num / 16, size);
    j++;
    if (rem < 10)
		temp = 48 + rem;
	else if (rem >= 10 && size == 0)
		temp = 87 + rem;
	else
		temp = 55 + rem;
	*(str + j) = temp;
	return (str);
}


/**
 * print_hex - converts to hexadecimal 
 * @x: int to change
 * Return: string to hexadecimal
 */
char *print_hex(va_list x)
{
    unsigned int num;

    num = va_arg(x, unsigned int);
    return (recurse(num, 0));
}


/**
 * print_hexa - converts to hexadecimal 
 * @X: int to change
 * Return: string to hexadecimal
 */
char *print_hexa(va_list X)
{
    unsigned int num;

    num = va_arg(X, unsigned int);
    return (recurse(num, 1));
}