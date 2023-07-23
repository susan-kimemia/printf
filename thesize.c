#include "main.h"
/**
 * _getsize - finds the szze of ARG
 * @format: str formmmtd
 * @h: llistt
 * Return: the_precisiision
 */
int _getsize(const char *format, int *h)
{
int wyomg = *h + 1;
int size = 0;
if (format[wyomg] == 'l')
size = LONG_SIZE;
else if (format[wyomg] == 'h')
size = SHORT_SIZE;
if (size == 0)
*h = wyomg - 1;
else
*h = wyomg;
return (size);
}

