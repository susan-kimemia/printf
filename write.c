#include "main.h"
/**
 * _writeCharacter - function prints a str
 * @c: character
 * @bbuff: buffer
 * @f:find flag
 * @the_witdth: wdth
 * @pprcion: SPecifys precisioN
 * @size: size
  * Return: char namba
 */
int _writeCharacter(char c, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{

int m = 0; /* init m to zero */
char grad = ' '; /* grad character creates space */
UUNUSSED(pprcion);
UUNUSSED(size);
if (f & _FLAG_ZERROO)
grad = '0';
bbuff[m++] = c;
bbuff[m] = '\0'; /* bafa index */
if (the_witdth > 1)
{
bbuff[SIZE_OFBUFFER - 1] = '\0'; /* checks for str end */
for (m = 0; m < the_witdth - 1; m++) /* loop */
bbuff[SIZE_OFBUFFER - m - 2] = grad;
if (f & _FLAG_MINUS)
return (write(1, &bbuff[0], 1) +
write(1, &bbuff[SIZE_OFBUFFER - m - 1], the_witdth - 1));
else
return (write(1, &bbuff[SIZE_OFBUFFER - m - 1], the_witdth - 1) +
write(1, &bbuff[0], 1));
}
return (write(1, &bbuff[0], 1));
}
/**
 * _writeNumber - str printer
 * @neg_tive: arg
 * @est: CHARACTER
 * @bbuff: buffer
 * @f: flag
 * @the_witdth:...wdth
 * @pprcion: PRRecision
 * @size: the size
 * Return: namba CHARACTER
 */
int _writeNumber(int neg_tive, int est, char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int _len = SIZE_OFBUFFER - est - 1;
char grad = ' ', morch = 0;
UUNUSSED(size);
if ((f & _FLAG_ZERROO) && !(f & _FLAG_MINUS))
grad = '0';
if (neg_tive)
morch = '-';
else if (f & _FLAG_ADD)
morch = '+';
else if (f & _FLAG_SPACE)
morch = ' ';
/* write function */
return (_writeN(est, bbuff, f, the_witdth, pprcion,
_len, grad, morch));
}
/**
 * _writeN - function writes namba
 * @est: start index
 * @bbuff: the bafa
 * @f: the flag
 * @the_witdth: the wdth
 * @ppricion: prcision
 * @_len: len
 * @grad: the paddingg character
 * @morc: more CHARACTER
 * Return: namba
 */
int _writeN(int est, char bbuff[],
int f, int the_witdth, int ppricion,
int _len, char grad, char morc)
{
int m, grad_start = 1;
if (ppricion == 0 && est == SIZE_OFBUFFER - 2 &&
bbuff[est] == '0' && the_witdth == 0)
return (0); /* chechs for condutions to write namba */
if (ppricion == 0 && est == SIZE_OFBUFFER - 2 && bbuff[est] == '0')
bbuff[est] = grad = ' ';
if (ppricion > 0 && ppricion < _len)
grad = ' ';
while (ppricion > _len) /* compare precscion & len */
bbuff[--est] = '0', _len++;
if (morc != 0)
_len++;
if (the_witdth > _len)
{
for (m = 1; m < the_witdth - _len + 1; m++)
bbuff[m] = grad;
bbuff[m] = '\0'; /* check line end */
if (f & _FLAG_MINUS && grad == ' ')
{
if (morc)
bbuff[--est] = morc;
return (write(1, &bbuff[est], _len) + write(1, &bbuff[1], m - 1));
}
else if (!(f & _FLAG_MINUS) && grad == ' ')
{
if (morc)
bbuff[--est] = morc; /* index reduce by iterating */
return (write(1, &bbuff[1], m - 1) + write(1, &bbuff[est], _len));
}
else if (!(f & _FLAG_MINUS) && grad == '0')
{
if (morc)
bbuff[--grad_start] = morc;
/* write function */
return (write(1, &bbuff[grad_start], m - grad_start) +
write(1, &bbuff[est], _len - (1 - grad_start)));
}
}
if (morc)
bbuff[--est] = morc;
return (write(1, &bbuff[est], _len));
}
/**
 * _writeUnsgnd - wwriting unsgnd namba
 * @neg_tive: -tive
 * @est: index char
 * @bbuff: buffer
 * @f: flag
 * @the_witdth: wdth
 * @pprcion: precccionn
 * @size: the size
 * Return: the namba of characters
 */
int _writeUnsgnd(int neg_tive, int est,
char bbuff[],
int f, int the_witdth, int pprcion, int size)
{
int _len = SIZE_OFBUFFER - est - 1, m = 0;
char grad = ' ';
UUNUSSED(neg_tive);
UUNUSSED(size);
if (pprcion == 0 && est == SIZE_OFBUFFER - 2 && bbuff[est] == '0')
return (0); /* check return success */
if (pprcion > 0 && pprcion < _len)
grad = ' ';
while (pprcion > _len) /* comparing precision & lngth */
{
bbuff[--est] = '0';
_len++; /* iterating len */
}
if ((f & _FLAG_ZERROO) && !(f & _FLAG_MINUS))
grad = '0'; /* equating pad to the str end */
if (the_witdth > _len)
{
for (m = 0; m < the_witdth - _len; m++)
bbuff[m] = grad;
bbuff[m] = '\0';/* bafa checks for line end */
if (f & _FLAG_MINUS)
{
return (write(1, &bbuff[est], _len) + write(1, &bbuff[0], m));
} /* write function */
else
{
return (write(1, &bbuff[0], m) + write(1, &bbuff[est], _len));
}
}
return (write(1, &bbuff[est], _len));
}
/**
 * _writePTR - it is writing the memory adrrress of the character
 * @bbuff: bafa
 * @est: the index
 * @_len: the len
 * @the_witdth: wdth
 * @f: flag
 * @grad: Padding char
 * @morc: more character
 * @grad_start: this is the start of padding
 * Return: namba of wrtn characters
 */
int _writePTR(char bbuff[], int est, int _len,
int the_witdth, int f, char grad, char morc, int grad_start)
{
int m; /* index var */
if (the_witdth > _len) /* comparing width and len */
{
for (m = 3; m < the_witdth - _len + 3; m++)
bbuff[m] = grad; /* the str buffer index m equated to padding */
bbuff[m] = '\0'; /* the buffer checking end of the str */
if (f & _FLAG_MINUS && grad == ' ')
{
bbuff[--est] = 'x';
bbuff[--est] = '0';
if (morc)
bbuff[--est] = morc;
/* write function */
return (write(1, &bbuff[est], _len) + write(1, &bbuff[3], m - 3));
}
/* entering a loop */
else if (!(f & _FLAG_MINUS) && grad == ' ')
{
bbuff[--est] = 'x';
bbuff[--est] = '0';
if (morc)
bbuff[--est] = morc; /* the buffer index reduced in each itrtn*/
/* write function */
return (write(1, &bbuff[3], m - 3) + write(1, &bbuff[est], _len));
}
else if (!(f & _FLAG_MINUS) && grad == '0')
{
if (morc)
bbuff[--grad_start] = morc;
bbuff[1] = '0';
bbuff[2] = 'x';
/* write function */
return (write(1, &bbuff[grad_start], m - grad_start) +
write(1, &bbuff[est], _len - (1 - grad_start) - 2));
}
}/* itterations */
bbuff[--est] = 'x';
bbuff[--est] = '0';
if (morc)
bbuff[--est] = morc;
/* write function */
return (write(1, &bbuff[est], SIZE_OFBUFFER - est - 1));
}
