#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{
va_list list;
int princahr = 0;
char *str, c;
if (format == NULL)
return (-1);
va_start(list, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '%')
princahr += write(1, "%", 1);
else if (*format == '\0')
return (-1);
else if (*format == 'c')
{
c = va_arg(list, int);
princahr += write(1, &c, 1);
}
else if (*format == 's')
{
str = va_arg(list, char *);
if (str == NULL)
str = "(null)";
princahr += write(1, str, strlen(str));
}
else
{
princahr += write(1, "%", 1);
princahr += write(1, format, 1);
}
}
else
princahr += write(1, format, 1);
format++;
}
va_end(list);
return (princahr);
}
