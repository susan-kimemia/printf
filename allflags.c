#include "main.h"
/**
 * _get_flaggs - finding & calc the_actve_flllagsss
 * @format: arg fmrtd
 * @h: arg index
 * Return: the_faflgs
 */
int _get_flaggs(const char *format, int *h)
{
int j, wyomg;
int f = 0;
const char _F_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int _F_ARR[] = {_FLAG_MINUS, _FLAG_ADD, _FLAG_ZERROO,
_FLAG_ASH, _FLAG_SPACE, 0};
for (wyomg = *h + 1; format[wyomg] != '\0'; wyomg++)
{
for (j = 0; _F_CH[j] != '\0'; j++)
if (format[wyomg] == _F_CH[j])
{
f |= _F_ARR[j];
break;
}
if (_F_CH[j] == 0)
break;
}
*h = wyomg - 1;
return (f);
}

