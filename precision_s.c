#include "main.h"
/**
 * getprecision - gets the preciision
 * @format: arg fomarttd
 * @h: arg
 * @list: the_list
 * Return: the_preciisionnn
 */
int getprecision(const char *format, int *h, va_list list)
{
int wyomg = *h + 1;
int pprcion = -1;
if (format[wyomg] != '.')
return (pprcion);
pprcion = 0; /* precisison being init to 0 */
for (wyomg += 1; format[wyomg] != '\0'; wyomg++)
{
if (itsAdigit(format[wyomg]))
{
pprcion *= 10;
pprcion += format[wyomg] - '0';
}
else if (format[wyomg] == '*')
{
wyomg++; /* iterration */
pprcion = va_arg(list, int);
break;
}
else
break; /* exit the loop if not found */
}
*h = wyomg - 1;
return (pprcion); /* returning the precision */
}

