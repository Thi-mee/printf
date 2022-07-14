#include "main.h"

/**
 * create_buffer - creates buffer to hold string until it's ready for print
 * Return: pointer to buffer created
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * check_buffer_overflow - if writing over buffer space,
 * print everything then revert length back to 0 to write at buffer start
 * @buffer: buffer holding string to print
 * @len: position in buffer
 * Return: length position
 */
int check_buffer_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}

/**
 * write_buffer - prints buffer, then frees it and frees va_list
 * @buffer: buffer holding print-ables
 * @len: length of print-able string
 * @list: va_list
 */
void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;

	buff = realloc(buffer, len); /* realloc to correct size */
	write(1, buff, len);		 /* print */

	free(buff);
	va_end(list);
}

/**
 * find_function - function that finds formats for _printf
 * calls the corresponding function.
 * @k: format (char, string, int, decimal)
 * Return: NULL or function associated ;
 */
char *(*find_function(char k))(va_list)
{
	int i = 0;
	format_specifier keys[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_dec},
		{'d', print_dec},
		{'r', print_rev},
		{'b', print_bin},
		{'u', print_unsig},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hexa},
		{'p', print_address},
		{'R', print_rot13},
		{'%', print_percent},
		{'\0', NULL}};

	while (keys[i].id != '\0')
	{
		if (keys[i].id == k)
			return (keys[i].func);
		i++;
	}
	return (NULL);
}
