#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#ifndef PRINTF_MAIN_H_
#define PRINTF_MAIN_H_
#define SIZE_OFBUFFER 1024
#define UUNUSSED(x) (void)(x)
/**
 * FLAGS
 */
#define _FLAG_ZERROO 4
#define _FLAG_MINUS 1
#define _FLAG_ADD 2
#define _FLAG_SPACE 16
#define _FLAG_ASH 8
/**
 * SIZES
 */
#define SHORT_SIZE 1
#define LONG_SIZE 2
/**
 * struct fmmmt - operattor strruct
 * @fmmmt: fomarrt 
 * @ction: Associated funct
 */
struct fmmmt
{
char fmmmt;
int (*ction)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmmmt fomart_t - operator struct
 * @fmmmt: fomarrrt
 * @fomart_t: Associated funct
 */
typedef struct fmmmt fomart_t;
int _printf(const char *fomart, ...);
int handle_print(const char *fmmmt, int *h,
va_list list, char bbuff[], int f, int the_witdth, int pprcion, int size);
/**
 * Funtions to print chars and strings
 */
int _pri_char(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _pri_pctage(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _pri_str(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
/**
 * Functions to print numbers
 */
int _pri_octall(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _pri_bnaryy(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int print_hexaupper(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _pri_unsgndd(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int print_hexadec(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _pri_int(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int print_hexa(va_list ttyype, char arr[],
char bbuff[], int f, char flag_ch, int the_witdth, int pprcion, int size);
/**
 * PRINT non printable CHAR
 */
int _pri_nonprintable(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
/**
 * PRINTING mem ADDREESSS
 */
int _pri_ptr(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
/**
 * HANDLING other specifiers
 */
int _get_flaggs(const char *format, int *h);
int _getsize(const char *format, int *h);

int _get_wdth(const char *format, int *h, va_list list);
int getprecision(const char *format, int *h, va_list list);
/**
 * PRINTING str in reverse
*/
int _priReverse(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
/**
 * PRINTING STR R
*/
int _priRSTRING(va_list ttyype, char bbuff[],
int f, int the_witdth, int pprcion, int size);
/**
 * HANDLES WDTH
 */
int _writePTR(char bbuff[], int est, int _len,
int the_witdth, int f, char grad, char morc, int grad_start);
int _writeNumber(int pos_tive, int est, char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _writeN(int est, char bafa[], int f, int the_witdth, int pprcion,
int _len, char grad, char morc);
int _writeUnsgnd(int neg_tive, int est,
char bbuff[],
int f, int the_witdth, int pprcion, int size);
int _writeCharacter(char c, char bbuff[],
int f, int the_witdth, int pprcion, int size);
/**
 * util
*/
int printable_(char);
int hexacode_append(char, char[], int);
int itsAdigit(char);
long int sizeNUMB_convert(long int namba, int size);
long int sizeUNSGND_convert(unsigned long int namba, int size);
#endif /* MAIN_H */
