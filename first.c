#include "main.h"
void print_buffer(char bbuff[], int *esttt);
/**
 * _printf - the_print_f funct
 * @format: arg str that is txt and fmrt specifaya
 * Return: the characters
 */
int _printf(const char *format, ...)
{
int y;
int puttd = 0, puttd_c = 0;
int f, the_witdth, pprcion, size; /* keeping track of the char pointed*/
int esttt = 0;
va_list list;
char bbuff[SIZE_OFBUFFER]; /* holding intermideate outputs*/
if (format == NULL)
return (-1);
va_start(list, format);
/* now loop iterattion starts*/
for (y = 0; format && format[y] != '\0'; y++)
{
if (format[y] != '%')
{
bbuff[esttt++] = format[y];
if (esttt == SIZE_OFBUFFER)
print_buffer(bbuff, &esttt);
puttd_c++; /* increment */
}
else
{
print_buffer(bbuff, &esttt);
f = _get_flaggs(format, &y);
the_witdth = _get_wdth(format, &y, list);
pprcion = getprecision(format, &y, list);
size = _getsize(format, &y);
++y; /* increment */
puttd = handle_print(format, &y, list, bbuff,
f, the_witdth, pprcion, size);
if (puttd == -1)
return (-1);
puttd_c += puttd;
}
}
print_buffer(bbuff, &esttt);
va_end(list);
return (puttd_c); /* end processing variable arg */
}
/**
 * print_buffer - fction prints bafa co_tent
 * @bbuff: the bafa
 * @esttt: the_i_n_dxx
 */
void print_buffer(char bbuff[], int *esttt)
{
if (*esttt > 0)
write(1, &bbuff[0], *esttt);
*esttt = 0;
}
