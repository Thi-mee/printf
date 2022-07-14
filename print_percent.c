#include "main.h"

char *print_percent(__attribute__((unused))va_list pc)
{
    char *p;

    p = malloc(sizeof(char));
    *p = '%';
    return (p);
}