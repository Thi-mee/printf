#include "main.h"
#include <stdio.h>

/**
 * print_string - takes string and return string
 * @str: string
 * Return: string
 */
char *print_string(va_list str)
{
	char *s;
	char *p;
	int len;

	s = va_arg(str, char *);
	if (s == NULL)
		s = "(null)";
	len = _strlen(s);

	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);

	return (_strcpy(p, s));
}


/**
 * print_address - prints an address 
 * 
 * @addr: address to be printed 
 * Return: char* 
 */
char *print_address(va_list addr){
	printf("Entered\n");
	char *s;
	char *p;
	int len;
	printf("Entered\n");
	s = va_arg(addr, char *);
	printf("Entered\n");
		printf("%s\n", *s);
	if (s == NULL)
		s = "(null)";
		

	len = _strlen(s);

	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);

	return (_strcpy(p, s));
}