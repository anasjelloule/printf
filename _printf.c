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
char *s;
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
if (format[i] == '%')
{
i++;
switch (format[i])
{
case '%':
princahr += _putchar('%');
break;
case 'c':
princahr += _putchar(va_arg(list, int));
break;
case 's':
s = va_arg(list, char *);
if (!s)
s = "(null)";
princahr += _puts(s);
break;
}
}
else
princahr += _putchar(format[i]);
va_end(list);
return (princahr);
}
