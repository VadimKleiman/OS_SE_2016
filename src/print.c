#include "ioport.h"
#include <stdarg.h>

#define D 1
#define I 2
#define U 3
#define O 4
#define X 5
#define C 6
#define S 7
#define HHD 8
#define HHI 9
#define HHU 10
#define HHO 11
#define HD 12
#define HI 13
#define HU 14
#define HO 15
#define HX 16
#define LLD 17
#define LLI 18
#define LLU 19
#define LLO 20
#define LLX 21
#define HHX 22

#define TO_HEX(i) (i <= 9 ? '0' + i : 'A' - 10 + i)

static void TryOut(unsigned short data)
{
    while(!(in8(0x3FD) & 32));
    out32(0x3F8, data);
}

static uint32_t decimal_octal32(uint32_t n)
{
    uint32_t rem, i=1, octal=0;
    while (n!=0)
    {
        rem=n%8;
        n/=8;
        octal+=rem*i;
        i*=10;
    }
    return octal;
}

static uint64_t decimal_octal64(uint64_t n)
{
    uint64_t rem, i=1, octal=0;
    while (n!=0)
    {
        rem=n%8;
        n/=8;
        octal+=rem*i;
        i*=10;
    }
    return octal;
}

static uint8_t decimal_octal8(uint8_t n)
{
    uint8_t rem, i=1, octal=0;
    while (n!=0)
    {
        rem=n%8;
        n/=8;
        octal+=rem*i;
        i*=10;
    }
    return octal;
}

static int64_t Rasriad64(int64_t enterNumber)
{
  int64_t n = enterNumber, x = 0;
  if (n == 0) return 1;
  while(n != 0){
     n /= 10;
     x++;
    }
  return x;
}

static int32_t Rasriad32(int32_t enterNumber)
{
  int32_t n = enterNumber, x = 0;
  if (n == 0) return 1;
  while(n != 0){
     n /= 10;
     x++;
    }
  return x;
}

static int16_t Rasriad16(int16_t enterNumber)
{
  int16_t n = enterNumber, x = 0;
  if (n == 0) return 1;
  while(n != 0){
     n /= 10;
     x++;
    }
  return x;
}

static uint64_t uRasriad64(uint64_t enterNumber)
{
  uint64_t n = enterNumber, x = 0;
  if (n == 0) return 1;
  while(n != 0){
     n /= 10;
     x++;
    }
  return x;
}

static uint32_t uRasriad32(uint32_t enterNumber)
{
  uint32_t n = enterNumber, x = 0;
  if (n == 0) return 1;
  while(n != 0){
     n /= 10;
     x++;
    }
  return x;
}
static uint8_t uRasriad8(uint8_t enterNumber)
{
  uint8_t n = enterNumber, x = 0;
  if (n == 0) return 1;
  while(n != 0){
     n /= 10;
     x++;
    }
  return x;
}

static int check(char * str)
{
    unsigned int i = 0;
    char tmp[3];
    while(str[i] != '\0' && i < 3)
    {
        tmp[i] = str[i];
        ++i;
    }
    i = 0;
    switch(tmp[i])
    {
        case 'd': return D; break;
        case 'i': return I; break;
        case 'u': return U; break;
        case 'o': return O; break;
        case 'c': return C; break;
        case 's': return S; break;
        case 'x': return X; break;
    }
    if(tmp[i] == 'h' && tmp[i + 1] == 'd')
        return HD;
    if(tmp[i] == 'h' && tmp[i + 1] == 'i')
        return HI;
    if(tmp[i] == 'h' && tmp[i + 1] == 'u')
        return HU;
    if(tmp[i] == 'h' && tmp[i + 1] == 'o')
        return HO;
    if(tmp[i] == 'h' && tmp[i + 1] == 'x')
        return HX;
    if(tmp[i] == 'h' && tmp[i + 1] == 'h' && tmp[i + 2] == 'd')
        return HHD;
    if(tmp[i] == 'h' && tmp[i + 1] == 'h' && tmp[i + 2] == 'i')
        return HHI;
    if(tmp[i] == 'h' && tmp[i + 1] == 'h' && tmp[i + 2] == 'u')
        return HHU;
    if(tmp[i] == 'h' && tmp[i + 1] == 'h' && tmp[i + 2] == 'o')
        return HHO;
    if(tmp[i] == 'l' && tmp[i + 1] == 'l' && tmp[i + 2] == 'd')
        return LLD;
    if(tmp[i] == 'l' && tmp[i + 1] == 'l' && tmp[i + 2] == 'i')
        return LLI;
    if(tmp[i] == 'l' && tmp[i + 1] == 'l' && tmp[i + 2] == 'u')
        return LLU;
    if(tmp[i] == 'l' && tmp[i + 1] == 'l' && tmp[i + 2] == 'o')
        return LLO;
    if(tmp[i] == 'l' && tmp[i + 1] == 'l' && tmp[i + 2] == 'x')
        return LLX;
    return 0;
}

int vprintf(char * format, va_list arg)
{
    unsigned int i = 0;
    unsigned int j = 0;

    unsigned short ch = 0;
    char * str;

    unsigned int len;

    unsigned int indexRas;
    unsigned int decimal = 1;

    char res[16];

    int64_t num64;
    int32_t num32;
    int16_t num16;

    uint64_t unum64;
    uint32_t unum32;
    uint8_t unum8;

    while(format[i] != '\0')
    {
        decimal = 1;
        ch = 0;
        if (format[i] == '%' && format[i + 1] != '\0')
            ch = check(&format[i + 1]);
        switch(ch)
        {
            case D:

            case I: 
                    num32 = va_arg (arg, int32_t);
                    if(num32 < 0)
                    {
                        TryOut('-');
                        num32 *= -1;
                    }
                    len = Rasriad32(num32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = num32 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }
                    ++i;
                    break;
            case U: 
                    unum32 = va_arg (arg, uint32_t);
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }
                    ++i;
                    break;
            case O: 
                    unum32 = va_arg (arg, uint32_t);
                    unum32 = decimal_octal32(unum32);
                    TryOut(48);
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }
                    ++i;
                    break;
            case X: 
                    unum32 = va_arg (arg, uint32_t);
                    if (unum32 <= 0xFFFF)
                    {
                        res[0] = TO_HEX(((unum32 & 0xF000) >> 12));
                        res[1] = TO_HEX(((unum32 & 0x0F00) >> 8));
                        res[2] = TO_HEX(((unum32 & 0x00F0) >> 4));
                        res[3] = TO_HEX(((unum32 & 0x000F)));
                        res[4] = '\0';   
                    }
                    TryOut('0');
                    TryOut('x');
                    while(res[j] != '\0')
                    {
                        TryOut(res[j]);
                        ++j;
                    }
                    j = 0; 
                    ++i; 
                    break;
            case C: 
                    TryOut((int8_t)va_arg(arg, int));
                    ++i; 
                    break;
            case S:
                    str = va_arg(arg, char *);
                    while(str[j] != '\0')
                    {
                        TryOut(str[j]);
                        ++j;
                    }
                    j = 0;
                    ++i;
                    break;
            case HHD: 
            case HHI:
                    TryOut((int8_t)va_arg(arg, signed int));
                    i += 3;
                    break;
            case HHO:
                    unum8 = va_arg (arg, uint32_t);
                    unum8 = decimal_octal8(unum8);
                    TryOut(48);
                    len = uRasriad8(unum8);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum8 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }
                    i += 3;
                    break;
            case HHU:
                    TryOut((uint8_t)va_arg(arg, unsigned int));
                    i += 3;
                    break;
            case HHX: 
                    unum8 = va_arg (arg, unsigned int);
                    if (unum8 <= 0xF)
                    {
                        res[0] = TO_HEX(((unum8 & 0xF)));
                        res[1] = '\0';   
                    }
                    TryOut('0');
                    TryOut('x');
                    while(res[j] != '\0')
                    {
                        TryOut(res[j]);
                        ++j;
                    }
                    j = 0;
                    i += 3;
                    break;
            case HD:
            case HI:
                    num16 = (int16_t)va_arg (arg, int);
                    if(num16 < 0){
                        TryOut('-');
                        num16 *= -1;
                    }
                    len = Rasriad16(num16);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = num16 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    } 
                    i += 2;
                    break;
            case HU:
                    unum32 = (uint32_t)va_arg (arg, int);
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    } 
                    i += 2;
                    break;
            case HO:
                    unum32 = va_arg (arg, uint32_t);
                    unum32 = decimal_octal32(unum32);
                    TryOut(48);
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }
                    i += 3; 
                    break;
            case HX:
                    unum32 = va_arg (arg, uint32_t);
                    if (unum32 <= 0xFFFF)
                    {
                        res[0] = TO_HEX(((unum32 & 0xF000) >> 12));
                        res[1] = TO_HEX(((unum32 & 0x0F00) >> 8));
                        res[2] = TO_HEX(((unum32 & 0x00F0) >> 4));
                        res[3] = TO_HEX(((unum32 & 0x000F)));
                        res[4] = '\0';   
                    }
                    TryOut('0');
                    TryOut('x');
                    while(res[j] != '\0')
                    {
                        TryOut(res[j]);
                        ++j;
                    }
                    j = 0;
                    i += 2; 
                    break;
            case LLD:
            case LLI:
                    num64 = va_arg (arg, int64_t);
                    if(num64 < 0){
                        TryOut('-');
                    
                    num64 *= -1;
                    }
                    len = Rasriad64(num64);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = num64 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    } 
                    i += 3;
                    break;
            case LLU:
                    unum64 = va_arg (arg, uint64_t);
                    len = uRasriad64(unum64);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum64 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }  
                    i += 3;
                    break;
            case LLO: 
                    unum64 = va_arg (arg, uint64_t);
                    unum64 = decimal_octal64(unum64);
                    TryOut(48);
                    len = uRasriad32(unum64);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum64 / decimal % 10; 
                        decimal /= 10; 
                        TryOut(48 + indexRas);
                    }
                    ++i;
                    break;
            case LLX:
                    unum64 = va_arg (arg, uint64_t);
                    if (unum64 <= 0xFFFFFFFFFFFFFFFF)
                    {
                        res[0] = TO_HEX(((unum64 &  0xF00000000000000) >> 56));
                        res[1] = TO_HEX(((unum64 &  0x0F0000000000000) >> 52));
                        res[2] = TO_HEX(((unum64 &  0x00F000000000000) >> 48));
                        res[3] = TO_HEX(((unum64 &  0x000F00000000000) >> 44));
                        res[4] = TO_HEX(((unum64 &  0x0000F0000000000) >> 40));
                        res[5] = TO_HEX(((unum64 &  0x00000F000000000) >> 36));
                        res[6] = TO_HEX(((unum64 &  0x000000F00000000) >> 32));
                        res[7] = TO_HEX(((unum64 &  0x0000000F0000000) >> 28));
                        res[8] = TO_HEX(((unum64 &  0x00000000F000000) >> 24));
                        res[9] = TO_HEX(((unum64 &  0x000000000F00000) >> 20));
                        res[10] = TO_HEX(((unum64 &  0x0000000000F0000) >> 16));
                        res[11] = TO_HEX(((unum64 &  0x00000000000F000) >> 12));   
                        res[12] = TO_HEX(((unum64 &  0x000000000000F00) >> 8));
                        res[13] = TO_HEX(((unum64 & 0x0000000000000F0) >> 4));
                        res[14] = TO_HEX( (unum64 & 0x00000000000000F));
                        res[15] = '\0';
                    }
                    TryOut('0');
                    TryOut('x');
                    while(res[j] != '\0')
                    {
                        TryOut(res[j]);
                        ++j;
                    }
                    j = 0; 
                    i += 3;
                    break;
            default: TryOut(format[i]); break;
        }
        ++i;
    }
    return 0;
}

int printf(char * format, ...)
{
    va_list pa;
    va_start(pa, format);
    vprintf(format, pa);
    va_end(pa);
    return 0;
}

int vsnprintf(char * s,unsigned int n, char * format, va_list arg)
{
    unsigned int i = 0;
    unsigned int j = 0;

    unsigned int index = 0;

    unsigned short ch = 0;
    char * str;

    unsigned int len;

    unsigned int indexRas;
    unsigned int decimal = 1;

    char res[9];

    int64_t num64;
    int32_t num32;
    int16_t num16;

    uint64_t unum64;
    uint32_t unum32;
    uint8_t unum8;

    while(format[i] != '\0')
    {
        decimal = 1;
        ch = 0;
        if (format[i] == '%' && format[i + 1] != '\0')
            ch = check(&format[i + 1]);
        switch(ch)
        {
            case D:

            case I: 
                    num32 = va_arg (arg, int32_t);
                    if(num32 < 0)
                    {
                        if(index < n) 
                        {
                            s[index] = '-';
                            ++index;
                        }
                        num32 *= -1;
                    }
                    
                    len = Rasriad32(num32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = num32 / decimal % 10; 
                        decimal /= 10;
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }
                    ++i;
                    break;
            case U: 
                    unum32 = va_arg (arg, uint32_t);
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }
                    ++i;
                    break;
            case O: 
                    unum32 = va_arg (arg, uint32_t);
                    unum32 = decimal_octal32(unum32);
                    if (index < n)
                    {
                        s[index] = 48;
                        ++index;
                    }
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }
                    ++i;
                    break;
            case X: 
                    unum32 = va_arg (arg, uint32_t);
                    if (unum32 <= 0xFFFF)
                    {
                        res[0] = TO_HEX(((unum32 & 0xF000) >> 12));
                        res[1] = TO_HEX(((unum32 & 0x0F00) >> 8));
                        res[2] = TO_HEX(((unum32 & 0x00F0) >> 4));
                        res[3] = TO_HEX(((unum32 & 0x000F)));
                        res[4] = '\0';   
                    }
                    if(index < n) 
                    {
                        s[index] = '0';
                        ++index;
                    }
                    if(index < n) 
                    {
                        s[index] = 'x';
                        ++index;
                    }
                    while(res[j] != '\0')
                    {
                        if(index < n) 
                        {
                            s[index] = res[j];
                            ++index;
                        }   
                        ++j;
                    }
                    j = 0; 
                    ++i; 
                    break;
            case C: 
                    if(index < n)
                    {
                        s[index] = (int8_t)va_arg(arg, int);
                        ++index;
                    }
                    ++i; 
                    break;
            case S:
                    str = va_arg(arg, char *);
                    while(str[j] != '\0')
                    {
                        if(index < n)
                        {
                            s[index] = str[j];
                            ++index;
                        }
                        ++j;
                    }
                    j = 0;
                    ++i;
                    break;
            case HHD: 
            case HHI:
                    if(index < n)
                    {
                        s[index] = (int8_t)va_arg(arg, signed int);
                        ++index;
                    }
                    i += 3;
                    break;
            case HHO:
                    unum8 = va_arg (arg, uint32_t);
                    unum8 = decimal_octal8(unum8);
                    if(index < n)
                    {
                        s[index] = 48;
                        ++index;
                    }
                    len = uRasriad8(unum8);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum8 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }
                    i += 3;
                    break;
            case HHU:
                    if(index < n) 
                        {
                            s[index] = (uint8_t)va_arg(arg, unsigned int);
                            ++index;
                        }
                    i += 3;
                    break;
            case HHX: 
                    unum8 = va_arg (arg, unsigned int);
                    if (unum8 <= 0xF)
                    {
                        res[0] = TO_HEX(((unum8 & 0xF)));
                        res[1] = '\0';   
                    }
                    if(index < n) 
                    {
                        s[index] = '0';
                        ++index;
                    }
                    if(index < n) 
                    {
                        s[index] = 'x';
                        ++index;
                    }
                    while(res[j] != '\0')
                    {
                        if(index < n) 
                        {
                            s[index] = res[j];
                            ++index;
                        }
                        ++j;
                    }
                    j = 0;
                    i += 3;
                    break;
            case HD:
            case HI:
                    num16 = (int16_t)va_arg (arg, int);
                    if(num16 < 0)
                    {
                        if(index < n) 
                        {
                            s[index] = '-';
                            ++index;

                        }
                        num16 *= -1;
                    }
                    
                    len = Rasriad16(num16);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = num16 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    } 
                    i += 2;
                    break;
            case HU:
                    unum32 = (uint32_t)va_arg (arg, int);
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    } 
                    i += 2;
                    break;
            case HO:
                    unum32 = va_arg (arg, uint32_t);
                    unum32 = decimal_octal32(unum32);
                    if(index < n) 
                        {
                            s[index] = (48);
                            ++index;
                        }
                    len = uRasriad32(unum32);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum32 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }
                    i += 3; 
                    break;
            case HX:
                    unum32 = va_arg (arg, uint32_t);
                    if (unum32 <= 0xFFFF)
                    {
                        res[0] = TO_HEX(((unum32 & 0xF000) >> 12));
                        res[1] = TO_HEX(((unum32 & 0x0F00) >> 8));
                        res[2] = TO_HEX(((unum32 & 0x00F0) >> 4));
                        res[3] = TO_HEX(((unum32 & 0x000F)));
                        res[4] = '\0';   
                    }
                    if(index < n) 
                    {
                        s[index] = '0';
                        ++index;
                    }
                    if(index < n) 
                    {
                        s[index] = 'x';
                        ++index;
                    }
                    while(res[j] != '\0')
                    {
                        if(index < n) 
                        {
                            s[index] = res[j];
                            ++index;
                        }
                        ++j;
                    }
                    j = 0;
                    i += 2; 
                    break;
            case LLD:
            case LLI:
                    num64 = va_arg (arg, int64_t);
                    if(num64 < 0)
                    {
                        if(index < n) 
                        {
                            s[index] = '-';
                            ++index;
                        }
                    num64 *= -1;
                    }
                    len = Rasriad64(num64);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = num64 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    } 
                    i += 3;
                    break;
            case LLU:
                    unum64 = va_arg (arg, uint64_t);
                    len = uRasriad64(unum64);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum64 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }  
                    i += 3;
                    break;
            case LLO: 
                    unum64 = va_arg (arg, uint64_t);
                    unum64 = decimal_octal64(unum64);
                    if(index < n) 
                        {
                            s[index] = (48);
                            ++index;
                        }
                    len = uRasriad32(unum64);
                    for(unsigned int j = 1; j < len; ++j)
                        decimal *= 10;
                    for(unsigned int j = 0; j < len; ++j)
                    {
                        indexRas = unum64 / decimal % 10; 
                        decimal /= 10; 
                        if(index < n) 
                        {
                            s[index] = (48 + indexRas);
                            ++index;
                        }
                    }
                    ++i;
                    break;
            case LLX:
                    unum64 = va_arg (arg, uint64_t);
                    if (unum64 <= 0xFFFFFFFFFFFFFFFF)
                    {
                        res[0] = TO_HEX(((unum64 &  0xF00000000000000) >> 56));
                        res[1] = TO_HEX(((unum64 &  0x0F0000000000000) >> 52));
                        res[2] = TO_HEX(((unum64 &  0x00F000000000000) >> 48));
                        res[3] = TO_HEX(((unum64 &  0x000F00000000000) >> 44));
                        res[4] = TO_HEX(((unum64 &  0x0000F0000000000) >> 40));
                        res[5] = TO_HEX(((unum64 &  0x00000F000000000) >> 36));
                        res[6] = TO_HEX(((unum64 &  0x000000F00000000) >> 32));
                        res[7] = TO_HEX(((unum64 &  0x0000000F0000000) >> 28));
                        res[8] = TO_HEX(((unum64 &  0x00000000F000000) >> 24));
                        res[9] = TO_HEX(((unum64 &  0x000000000F00000) >> 20));
                        res[10] = TO_HEX(((unum64 &  0x0000000000F0000) >> 16));
                        res[11] = TO_HEX(((unum64 &  0x00000000000F000) >> 12));   
                        res[12] = TO_HEX(((unum64 &  0x000000000000F00) >> 8));
                        res[13] = TO_HEX(((unum64 & 0x0000000000000F0) >> 4));
                        res[14] = TO_HEX( (unum64 & 0x00000000000000F));
                        res[15] = '\0';
                    }
                    if(index < n) 
                    {
                        s[index] = '0';
                        ++index;
                    }
                    if(index < n) 
                    {
                        s[index] = 'x';
                        ++index;
                    }
                    while(res[j] != '\0')
                    {
                         if(index < n) 
                        {
                            s[index] = res[j];
                            ++index;
                        }
                        ++j;
                    }
                    j = 0; 
                    i += 3;
                    break;
            default: if(index < n) 
                        {
                            s[index] = format[i];
                            ++index;
                        } break;
        }
        ++i;
    }
    s[index] = '\0';
    return 0;
}

int snprintf(char * s, unsigned int n, char * format, ...)
{
    va_list pa;
    va_start(pa, format);
    vsnprintf(s, n - 1, format, pa);
    va_end(pa);
    return 0;
}