#include "main.h"
/**
 * _pri_char - it prnts the characters
 * @ttyype: arg
 * @bbuff: bafa
 * @f: f-l_ags
 * @the_witdth: wdth
 * @pprcion: pprcion
 * @size: size
 * Return: characters namba
 */
int _pri_char(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
char c = va_arg(ttyype, int); /* get character arguement from the string */
return (_writeCharacter(c, bbuff, f, the_witdth, pprcion, size));
}
/**
 * _pri_str - str
 * @ttyype: arg var (va_list)
 * @bbuff: bafa storage of output
 * @f: the flags
 * @the_witdth: wdth
 * @pprcion: pprcion
 * @size: size ya bafa
 * Return: namba
 */
int _pri_str(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int _len = 0; /* var for lgth*/
int e; /* var for str handlliing */
char *str = va_arg(ttyype, char *);
UUNUSSED(bbuff);
UUNUSSED(f);
UUNUSSED(the_witdth);
UUNUSSED(pprcion);
UUNUSSED(size);
if (str == NULL)
{
str = "(null)"; /* null string, handle it as a special case*/
if (pprcion >= 6)
str = "      ";
}
while (str[_len] != '\0')
_len++;
if (pprcion >= 0 && pprcion < _len)
_len = pprcion;
if (the_witdth > _len)
{
if (f & _FLAG_MINUS)
{
write(1, &str[0], _len); /* call a function to handle writing */
for (e = the_witdth - _len; e > 0; e--)
write(1, " ", 1);
return (the_witdth);
}
else
{
for (e = the_witdth - _len; e > 0; e--)
write(1, " ", 1);
write(1, &str[0], _len);
return (the_witdth);
}
}
return (write(1, str, _len));
}
/**
 * _pri_pctage - the pe_centa_ge
 * @ttyype: arg
 * @bbuff: bafa
 * @f: flags
 * @the_witdh: wdth
 * @pprcion: pprcion
 * @size: szeei
 * Return: namba
 */
int _pri_pctage(va_list ttyype, char bbuff[],
int f, int the_witdh, int pprcion, int size)
{
UUNUSSED(bbuff);
UUNUSSED(pprcion);
UUNUSSED(size);
UUNUSSED(f);
UUNUSSED(the_witdh); /* marking the variables as unused to avoid... */
UUNUSSED(ttyype); /* ... comiler warning */
return (write(1, "%%", 1)); /* write the percentage sign */
}
/**
 * _pri_int - an_integer
 * @ttyype: arg
 * @bbuff: bafa
 * @f: flags
 * @the_witdth: wdth
 * @pprcion: pprcion
 * @size: the_s_i_ze
 * Return: namba
 */
int _pri_int(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int y = SIZE_OFBUFFER - 2;
int neg_tive = 0;
long int n = va_arg(ttyype, long int);
unsigned long int namba;
n = sizeNUMB_convert(n, size);
if (n == 0)
bbuff[y--] = '0';
bbuff[SIZE_OFBUFFER - 1] = '\0';
namba = (unsigned long int)n;
if (n < 0)
{
namba = (unsigned long int)((-1) * n);
neg_tive = 1; /* equating the negative to zero */
}
while (namba > 0)
{
bbuff[y--] = (namba % 10) + '0';
namba /= 10;
}
y++; /* incrementing y */
return (_writeNumber(neg_tive, y, bbuff, f, the_witdth, pprcion, size));
}
/**
 * _pri_bnaryy - binarry
 * @ttyype: arg
 * @bbuff: bafa
 * @f: flgs
 * @the_witdth: wdth
 * @pprcion: pprcion
 * @size: the_s_ze
 * Return: namba
 */
int _pri_bnaryy(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
unsigned int j, p;
unsigned int k, sum; /* unsigned to avoid compiler warning */
unsigned int a[32];
int index;
UUNUSSED(pprcion);
UUNUSSED(bbuff);
UUNUSSED(the_witdth);
UUNUSSED(f);
UUNUSSED(size);
j = va_arg(ttyype, unsigned int); /* get the nxt unsigned int var */
p = 2147483648; /* initializing a power */
a[0] = j / p;
for (k = 1; k < 32; k++)
{
p /= 2; /* move to the next lower power 2 */
a[k] = (j / p) % 2; /* calculating the value of the bit position */
}
for (k = 0, sum = 0, index = 0; k < 32; k++)
{
sum += a[k]; /* incement sum */
if (sum || k == 31) /* if the sum is non-zero or we reached lst limit*/
{
char z = '0' + a[k]; /* covert bit value */
write(1, &z, 1);
index++; /* incrementing */
}
}
return (index);
}
