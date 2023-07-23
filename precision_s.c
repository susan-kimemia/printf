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
pprcion = 0; /* precision is initialized to zero */
/* the fnction starts checking for dgts using loop */
for (wyomg += 1; format[wyomg] != '\0'; wyomg++)
{
if (itsAdigit(format[wyomg]))
{
pprcion *= 10;
pprcion += format[wyomg] - '0';
}
else if (format[wyomg] == '*')
{
wyomg++; /* iterration of index */
pprcion = va_arg(list, int); /* precison is equated to args */
break;
}
else
break; /* exiting a loop */
}
*h = wyomg - 1;
return (pprcion); /* return precision */
}

