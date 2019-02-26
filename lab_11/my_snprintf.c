#include <string.h>
#include <stdarg.h>

#include "func.h"
#include "my_snprintf.h"

/*
 Функция реализации snprintf для работы со спецификатрами %i, %x, %d и h

 @param s [in]
 @param n [in]
 @param format [in]

 @return возвращает длину считанной строки или -1 в случае переполнения
 */

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list argv;
    va_start(argv, format);

    s[n-1] = 0;
    int flag_finish = 0;
    int s_len = 0, result;
    size_t len_last_word = 0;

    while (!flag_finish && *format && s_len<n)
    {
        if (*format == '%')
        {
            format++;
            switch(*format)
            {
                case '%':
                    *s = '%';
                    move_ptr(&s, &s_len, 1);
                    break;
                case 'l':
                    format++;
                    flag_finish = numbers(&format, &s, &s_len,
                                          (int)va_arg(argv, long int));
                    break;
                default:
                    flag_finish = numbers(&format, &s, &s_len,
                                          (int)va_arg(argv, int));
                    break;
            }
        }
        else
        {
            *s = *format;
            move_ptr(&s, &s_len, 1);
        }
        format++;
    }

    va_end(argv);
    *s = 0;

    if (s_len >= n)
        result = -1;
    else
        result = s_len;

    return result;
}
