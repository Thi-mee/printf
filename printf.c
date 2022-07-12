#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: initial string with identifiers
 * Return: size the output text;
 */
int _printf(const char *format, ...)
{
	char *buffer, *str;
	int len = 0, total_len = 0;
	va_list argList;
	char *(*f)(va_list);
	int i = 0, j;

	if (format == NULL)
		return (-1);

	va_start(argList, format);
	buffer = create_buffer();

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into buffer until '%' */
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else /* If % */
		{
			i++;
			if (format[i] == '\0') /* handle single ending % */
			{
				va_end(argList);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[i];
				total_len++;
			}
			else
			{
				f = find_function(format[i]); /* grab function */
				if (f == NULL)				  /* handle fake id */
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%';
					total_len++;
					buffer[len++] = format[i];
					total_len++;
				}
				else /* return string, copy to buffer */
				{
					str = f(argList);
					if (str == NULL)
					{
						va_end(argList);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[j];
						total_len++;
						j++;
					}
					free(str);
				}
			}
			i++;
		}
	}
	write_buffer(buffer, len, argList);
	return (total_len);
}
