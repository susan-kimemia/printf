#include "main.h"
/**
 * _pri_unsgndd - prn namba
 * @ttyype: arg
 * @bbuff: bafa containing stored val
 * @f: f_lag_s
 * @the_witdth: wdth
 * @pprcion: pprscion
 * @size: the sze
 * Return: namba of prntd characters
 */
int _pri_unsgndd(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int m = SIZE_OFBUFFER - 2; /* initialize 'm' to index in 'bbuff' */
unsigned long int namba = va_arg(ttyype, unsigned long int);
/* gets nxt usngnd long */
namba = sizeUNSGND_convert(namba, size);
if (namba == 0)
bbuff[m--] = '0';
bbuff[SIZE_OFBUFFER - 1] = '\0'; /* if namba iszero, store '0' */
while (namba > 0) /* converts the unsigned long int to its decimal */
{
bbuff[m--] = (namba % 10) + '0'; /* gets least significant dgt */
namba /= 10;
}
m++; /* increment 'm' to point to the first dgt */
/* call a function to handle writing */
return (_writeUnsgnd(0, m, bbuff, f, the_witdth, pprcion, size));
}
/**
 * _pri_octall - unsgd octal namba
 * @ttyype: arg
 * @bbuff: bafa
 * @f: f_laggss
 * @the_witdth: wdth
 * @pprcion: prscion
 * @size: the szei
 * Return: namba of the character
 */
int _pri_octall(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int m = SIZE_OFBUFFER - 2; /* initialize 'm' to index in 'bbuff' */
unsigned long int namba = va_arg(ttyype, unsigned long int);
unsigned long int init_namba = namba;
UUNUSSED(the_witdth);
namba = sizeUNSGND_convert(namba, size);
if (namba == 0) /* check if namba is equal to zero */
bbuff[m--] = '0';
bbuff[SIZE_OFBUFFER - 1] = '\0'; /* if namba iszero, store '0' */
while (namba > 0) /* converts the unsigned long int to its decimal */
{
bbuff[m--] = (namba % 8) + '0';
namba /= 8;
}
if (f & _FLAG_ASH && init_namba != 0)
bbuff[m--] = '0';
m++; /* incrremnting m to point to the 1stdgt */
/* call a function to handle writing */
return (_writeUnsgnd(0, m, bbuff, f, the_witdth, pprcion, size));
}
/**
 * print_hexadec - unsgd hexadec
 * @ttyype: arg
 * @bbuff: bafa
 * @f:f_l_agss
 * @the_witdth: wdth
 * @pprcion: rpreciccsion
 * @size: teh sizze
 * Return: namba of character printed
 */
int print_hexadec(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
return (print_hexa(ttyype, "0123456789abcdef", bbuff,
f, 'x', the_witdth, pprcion, size));
}
/**
 * print_hexaupper - upper_hexa_dec
 * @ttyype: arg
 * @bbuff: bafa
 * @f: f_lag_s
 * @the_witdth: wdth
 * @pprcion: prcsion
 * @size: the ssizze
 * Return: namba chacter thats prntd
 */
int print_hexaupper(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
return (print_hexa(ttyype, "0123456789ABCDEF", bbuff,
f, 'X', the_witdth, pprcion, size));
}
/**
 * print_hexa - hexa in upper or low_er
 * @ttyype: arg
 * @arr: the array
 * @bbuff: bafa
 * @f: f_l_aggs
 * @f_ch: i_cal_clationss of the_f lags
 * @the_witdth: wdth
 * @pprcion: pcsion
 * @size: the size
 * Return: namba
 */
int print_hexa(va_list ttyype, char arr[], char bbuff[],
int f, char f_ch, int the_witdth, int pprcion, int size)
{
int m = SIZE_OFBUFFER - 2;
unsigned long int namba = va_arg(ttyype, unsigned long int);
unsigned long int init_namba = namba;
UUNUSSED(the_witdth);
namba = sizeUNSGND_convert(namba, size);
if (namba == 0)
bbuff[m--] = '0';
bbuff[SIZE_OFBUFFER - 1] = '\0'; /* initialize 'm' to index in 'bbuff' */
while (namba > 0) /* converts the unsigned long int */
{
bbuff[m--] = arr[namba % 16];
namba /= 16;
}
if (f & _FLAG_ASH && init_namba != 0)
{
bbuff[m--] = f_ch;
bbuff[m--] = '0';
}
m++; /* incrementing m to point to the 1st dgt*/
/* call a function to handle writing */
return (_writeUnsgnd(0, m, bbuff, f, the_witdth, pprcion, size));
}
