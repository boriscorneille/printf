#include "main.h"

/**
 * _printf - Custom implementation of the printf function.
 * @format: The format string containing the directives and text to be printed.
 *
 * Return: The total number of characters printed (excluding the null terminator),
 *         or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
    int i, print = 0, p_char = 0;
    int flg, wdth, pre, s, buf_i = 0;
    va_list lst;
    char buf[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(lst, format);

    for (i = 0; format && format[i] != '\0'; i++) {
        if (format[i] != '%') {
            buf[buf_i++] = format[i];
            if (buff_ind == BUFF_SIZE) {
                p_buf(buf, &buf_i);
            }
            p_char++;
        } else {
            p_buf(buf, &buf_i);
            flg = g_flg(format, &x);
            wdth = g_wdth(format, &x, lst);
            pre = g_pre(format, &x, lst);
            s = g_s(format, &x);
            ++i;
            print = all_handle(format, &i, lst, buf,
                flg, wdth, pre, s);
            if (print == -1) {
                return (-1);
            }
            p_char += print;
        }
    }

    p_buf(buf, &buf_i);

    va_end(lst);

    return (p_char);
}

/**
 * p_buf - Prints the contents of the buffer to the standard output.
 * @buf: The character buffer containing the text to be printed.
 * @buf_i: The current index in the buffer.
 */
void p_buf(char buf[], int *buf_i)
{
    if (*buf_i > 0) {
        write(1, &buf[0], *buf_i);
    }

    *buf_i = 0;
}
