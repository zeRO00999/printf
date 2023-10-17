#include "main.h"

call_t container[] = {
    {'c', parse_char}, {'s', parse_str}, {'i', parse_int}, {'d', parse_int},
    {'%', parse_perc}, {'b', parse_bin}, {'o', parse_oct}, {'x', parse_hex},
    {'X', parse_X}, {'u', parse_uint}, {'R', parse_R13}, {'r', parse_rev},
    {'\0', NULL}
};

int _printf(const char *format, ...) {
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

