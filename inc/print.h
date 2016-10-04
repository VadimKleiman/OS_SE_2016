#ifndef __PRINT_H__
#define __PRINT_H__

#include <stdarg.h>

int printf(char *format, ...);
int vprintf(char * format, va_list arg);
int snprintf ( char * s, unsigned int n, char * format, ... );
int vsnprintf ( char * s, unsigned int n, char * format, va_list arg );

#endif