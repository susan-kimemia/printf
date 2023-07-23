#include "main.h"
/**
 * _get_wdth - findg the wdth
 * @format: the_fmart
 * @h: arg
 * @list: the_list
 * Return: the_wdth
 */
int _get_wdth(const char *format, int *h, va_list list)
{
int wyomg;
int the_witdth = 0;
for (wyomg = *h + 1; format[wyomg] != '\0'; wyomg++)
{
if (itsAdigit(format[wyomg]))
{
the_witdth *= 10;
the_witdth += format[wyomg] - '0';
}
else if (format[wyomg] == '*')
{
wyomg++;
the_witdth = va_arg(list, int);
break;
}
else
break;
}
*h = wyomg - 1;
return (the_witdth);
}
