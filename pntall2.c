#include "main.h"
/**
 * _pri_ptr - this fnction do prnnt a ptrrr
 * @ttyype: the_taip of arg
 * @bbuff: the bafa
 * @f: the__f_lag_s
 * @the_witdth: THE_wdth
 * @pprcion: _the_p_ricisioiin
 * @size: the SIZ_E__
 * Return: the namba of characters
 */
int _pri_ptr(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
char morc = 0;
char grad = ' ';
int est = SIZE_OFBUFFER - 2, _len = 2, grad_start = 1;
unsigned long namba_addrs;/* using unsgned to evade compiler warning */
char arr[] = "0123456789abcdef";
void *addrs = va_arg(ttyype, void *);
UUNUSSED(the_witdth);
UUNUSSED(size);
if (addrs == NULL) /* check if adress is empty */
return (write(1, "(nil)", 5));
bbuff[SIZE_OFBUFFER - 1] = '\0';/* if namba is zero store '0' */
UUNUSSED(pprcion);
namba_addrs = (unsigned long)addrs;
while (namba_addrs > 0)
{
bbuff[est--] = arr[namba_addrs % 16];
namba_addrs /= 16;
_len++;/* itteration */
}
if ((f & _FLAG_ZERROO) && !(f & _FLAG_MINUS))
grad = '0';
if (f & _FLAG_ADD)
morc = '+', _len++;
else if (f & _FLAG_SPACE)
morc = ' ', _len++;
est++;/* itterate */
/**
 * return (write(1, &bbuff[m], SIZE_OFBUFFER - m - 1));
 * @grad_start: index
 */
return (_writePTR(bbuff, est, _len,
the_witdth, f, grad, morc, grad_start)); /* get a write fctn */
}
/**
 * _pri_nonprintable - the nonprintable charact
 * @ttyype: typesof arg lst
 * @bbuff: the_bafa
 * @f: the_fL_ags
 * @the_witdth: wdth
 * @pprcion: the_P_recis_onn
 * @size: the siZe
 * Return: the namba printed of the cha_racters
 */
int _pri_nonprintable(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int m = 0;
int offset = 0;
char *str = va_arg(ttyype, char *);
UUNUSSED(f);
UUNUSSED(the_witdth);
UUNUSSED(pprcion);
UUNUSSED(size);
if (str == NULL) /* check if string is null */
return (write(1, "(null)", 6)); /* write fction */
while (str[m] != '\0')
{
if (printable_(str[m]))
bbuff[m + offset] = str[m];
else
offset += hexacode_append(str[m], bbuff, m + offset);
m++; /* iterration */
}
bbuff[m + offset] = '\0'; /* init m to index bbuff */
return (write(1, bbuff, m + offset));
}
/**
 * _priReverse - it is printing str in re_verse
 * @ttyype: arg
 * @bbuff: bafa
 * @f: ff-l_ags
 * @the_witdth: wdth
 * @pprcion: pre_cision
 * @size: the_s_ize
 * Return: namba of character that is prntd
 */
int _priReverse(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
char *str; /* character array */
int m;
int fc_ount = 0; /* assigning the var to 0 */
UUNUSSED(bbuff);
UUNUSSED(f);
UUNUSSED(the_witdth);
UUNUSSED(size);
str = va_arg(ttyype, char *);
if (str == NULL) /* compare str to null */
{
UUNUSSED(pprcion);
str = ")Null("; /* reversively equating str to null */
}
for (m = 0; str[m]; m++)
;
for (m = m - 1; m >= 0; m--)
{
char z = str[m];
write(1, &z, 1);
fc_ount++; /* iteration */
}
return (fc_ount);
}
/**
 * _priRSTRING - str prntg
 * @ttyype: arg
 * @bbuff: Buffer array to handle print
 * @f:the falags
 * @the_witdth: wdth
 * @pprcion: pprcion
 * @size: the sze
 * Return: character namba
 */
int _priRSTRING(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
char x;
char *str;
unsigned int m;
unsigned int n;
int fc_ount = 0;
char ascnd[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char dscnd[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(ttyype, char *);
UUNUSSED(bbuff);
UUNUSSED(f);
UUNUSSED(the_witdth);
UUNUSSED(pprcion);
UUNUSSED(size);
if (str == NULL) /* checking if string is null */
str = "(AHYY)";
for (m = 0; str[m]; m++)
{
for (n = 0; ascnd[n]; n++)
{
if (ascnd[n] == str[m])
{
x = dscnd[n];
write(1, &x, 1);
fc_ount++; /* iterration */
break;
}
}
if (!ascnd[n])
{
x = str[m];
write(1, &x, 1);
fc_ount++; /* iterration */
}
}
return (fc_ount);
}

