#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;  /* To keep track of the numbr of characters printed */

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char*);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count++;
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}

int main()
{
    _printf("Education is when you read the fine print. Experience is what you get if you don't.\n");
    _printf("The value of %s is %d.\n", "x", 42);

    return 0;
}
