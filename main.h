#ifndef H_FILE
#define H_FILE

#include <stdarg.h> /* va_list */
#include <stdlib.h> /* malloc, free */
#include <unistd.h> /* write */

/**
 * struct types - struct
 * @id: identifier of what to print
 * @func: function 
 */
typedef struct types
{
	char id;
	char* (*func)(va_list);
} format_specifier;

/* helper functions */
char *create_buffer(void);
int check_buffer_overflow(char *buffer, int len);
void write_buffer(char *buffer, int len, va_list argList);
char* (*find_function(char k))(va_list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);


/* printf functions */
int _printf(const char *format, ...);
char *print_char(va_list c);
char *print_string(va_list s);
char *print_dec(va_list d);
char *print_rev(va_list r);
char *print_bin(va_list b);
char *print_unsig(va_list u);
char *print_octal(va_list o);
char *print_rot13(va_list R);

#endif