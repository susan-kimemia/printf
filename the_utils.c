#include "main.h"
/**
 * printable_ - finds if a character can be printed
 * @c: the character
 * Return: one when char can be printed else 0
 */
int printable_(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
 * hexacode_append - it is appending ascci in hexa-decimal
 * @bbuff: buffer
 * @i: start of ppaddinggg
 * @val_ascii: the ascii values
 * Return: three
 */
int hexacode_append(char val_ascii, char bbuff[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (val_ascii < 0)
val_ascii *= -1;
bbuff[i++] = '\\';
bbuff[i++] = 'x';
bbuff[i++] = map_to[val_ascii / 16];
bbuff[i] = map_to[val_ascii % 16];
return (3);
}
/**
 * itsAdigit - finds a dgt
 * @c: the character
 * Return: one if dgt else zero
 */
int itsAdigit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
/**
 * sizeNUMB_convert - convert namba to the required sizze
 * @namba: the namba being convrt
 * @size: namba that shows the ssize requird
 * Return: converted sze
 */
long int sizeNUMB_convert(long int namba, int size)
{
if (size == LONG_SIZE)
return (namba);
else if (size == SHORT_SIZE)
return ((short)namba);
return ((int)namba);
}
/**
 * sizeUNSGND_convert - convrts namba to spec sizeee
 * @namba: namba convart
 * @size: size
 * Return: convrtd namba
 */
long int sizeUNSGND_convert(unsigned long int namba, int size)
{
if (size == LONG_SIZE)
return (namba);
else if (size == SHORT_SIZE)
return ((unsigned short)namba);
return ((unsigned int)namba);
}

