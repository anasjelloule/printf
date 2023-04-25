#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{
int princahr = 0;
va_list list;
char *s;
if (format == NULL)
return (-1);
va_start(list, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '%')
princahr += _putchar('%');
else if (*format == 'c')
princahr += _putchar(va_arg(list, int));
else if (*format == 's')
{
s = va_arg(list, char *);
if (!s)
s = "(null)";
princahr += _puts(s);
}
else
{
princahr += write(1, "%", 1);
princahr += write(1, format, 1);
}
}
else
princahr += _putchar(*format);
format++;
}
va_end(list);
return (princahr);
}
