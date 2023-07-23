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
char c = va_arg(ttyype, int);
return (_writeCharacter(c, bbuff, f, the_witdth, pprcion, size));
}
/**
 * _pri_str - str
 * @ttyype: arg
 * @bbuff: bafa
 * @f: the flags
 * @the_witdth: wdth
 * @pprcion: pprcion
 * @size: size
 * Return: namba
 */
int _pri_str(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int _len = 0, i;
char *str = va_arg(ttyype, char *);
UUNUSSED(bbuff);
UUNUSSED(f);
UUNUSSED(the_witdth);
UUNUSSED(pprcion);
UUNUSSED(size);
if (str == NULL)
{
str = "(null)";
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
write(1, &str[0], _len);
for (i = the_witdth - _len; i > 0; i--)
write(1, " ", 1);
return (the_witdth);
}
else
{
for (i = the_witdth - _len; i > 0; i--)
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
UUNUSSED(ttyype);
UUNUSSED(bbuff);
UUNUSSED(f);
UUNUSSED(the_witdh);
UUNUSSED(pprcion);
UUNUSSED(size);
return (write(1, "%%", 1));
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
neg_tive = 1;
}
while (namba > 0)
{
bbuff[y--] = (namba % 10) + '0';
namba /= 10;
}
y++;
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
unsigned int j, p, k, sum;
unsigned int a[32];
int index;
UUNUSSED(bbuff);
UUNUSSED(f);
UUNUSSED(the_witdth);
UUNUSSED(pprcion);
UUNUSSED(size);
j = va_arg(ttyype, unsigned int);
p = 2147483648;
a[0] = j / p;
for (k = 1; k < 32; k++)
{
p /= 2;
a[k] = (j / p) % 2;
}
for (k = 0, sum = 0, index = 0; k < 32; k++)
{
sum += a[k];
if (sum || k == 31)
{
char z = '0' + a[k];
write(1, &z, 1);
index++;
}
}
return (index);
}
