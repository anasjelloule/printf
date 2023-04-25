#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{
int i, princahr = 0;
va_list list;
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
if (format[i] != '%')
princahr++;
va_end(list);
return (princahr);
}
