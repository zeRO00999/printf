#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list arg;
    char buffer[2000];
    int i = 0, buff_count = 0;

    if (!format)
        return -1;

    va_start(arg, format);

    while (format[i])
    {
        int j; 

        if (format[i] == '%')
        {
            i++; 
            if (format[i] == '\0')
                break; 

            for (j = 0; container[j].t != '\0'; j++)
            {
                if (format[i] == container[j].t)
                {
                    buff_count = container[j].f(buffer, arg, buff_count);
                    break;
                }
            }

            if (container[j].t == '\0')
            {
                buffer[buff_count] = '%';
                buff_count++;
            }
        }
        else
        {
            buffer[buff_count] = format[i];
            buff_count++;
        }
        i++;
    }

    va_end(arg);
    buffer[buff_count] = '\0';
    print_buff(buffer, buff_count);

    return buff_count;
}

