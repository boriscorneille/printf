#include "main.h"

/**
 * p_unsigned - Print an unsigned integer number
 * @types: va_list containing the argument to print
 * @buf: Buffer to store the resulting string
 * @flg: Formatting flags
 * @wdth: Minimum field width
 * @pre: Minimum number of digits to be printed
 * @s: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: console characters
 */
int p_unsigned(va_list types, char buf[],
        int flg, int wdth, int pre, int s)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);

        num = convert_s_unsigned(num, s);

        if (num == 0)
                buf[i--] = '0';

        buf[BUFF_SIZE - 1] = '\0';

        while (num > 0) {
                buf[i--] = (num % 10) + '0';
                num /= 10;
        }

        i++;

        return Enter_unsigned(0, i, buf, flg, wdth, pre, s);
}

/**
 * p_octal - Print an unsigned number in octal format
 * @types: va_list containing the argument to print
 * @buf: Buffer to store the resulting string
 * @flg: Formatting flags
 * @wdth: Minimum field width
 * @pre: Minimum number of digits to be printed
 * @s: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: The number of characters printed
 */
int p_octal(va_list types, char buf[],
        int flags, int wdth, int pre, int s)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(wdth);

        num = convert_s_unsigned(num, s);

        if (num == 0)
                buf[i--] = '0';

        buf[BUFF_SIZE - 1] = '\0';

        while (num > 0) {
                buf[i--] = (num % 8) + '0';
                num /= 8;
        }

        if (flg & F_HASH && init_num != 0)
                buf[i--] = '0';

        i++;

        return  Enter_unsigned(0, i, buf, flg, wdth, pre, s);
}

/**
 * p_hexdec - show all numbers in hexadecimal format
 * @types: va_list containing all argumen
 * @buf: buff memory used to store the resulting string
 * @flg: frmt flags
 * @wdth: check field width
 * @pre: check number of digits to be printed
 * @s: check Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: All numbers of characters printed
 */
int p_hexdec(va_list types, char buf[],
        int flg, int wdth, int pre, int s)
{
        return p_hexa(types, "0123456789abcdef", buf,
                flg, 'x', wdth, pre, s);
}

/**
 * p_hex_up - show all numbers in hexadecimal format
 * @types: va_list containing all argumen
 * @buf: buff memory used to store the resulting string
 * @flg: frmt flags
 * @wdth: check field width
 * @pre: check number of digits to be printed
 * @s: check Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: All numbers of characters printed
 */

int p_hex_up(va_list types, char buf[],
        int flg, int wdth, int pre, int s)
{
        return p_hexa(types, "0123456789ABCDEF", buf,
                flg, 'X', wdth, pre, s);
}


/**
 * p_hex_up - show all numbers in hexadecimal format
 * @types: va_list containing all argumen
 * @buf: buff memory used to store the resulting string
 * @flg: frmt flags
 * flg_ch: flag characters
 * @wdth: check field width
 * @pre: check number of digits to be printed
 * @s: check Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: All numbers of characters printed
 */
int p_hexa(va_list types, char map_to[],
char buf[], int flg, char flg_ch, int wdth, int pre, int s)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(wdth);

        num = convert_s_unsigned(num, s);

        if (num == 0)
                buf[i--] = '0';

        buf[BUFF_SIZE - 1] = '\0';

        while (num > 0) {
                buf[i--] = map_to[num % 16];
                num /= 16;
        }

        if (flg & F_HASH && init_num != 0) {
                buf[i--] = flg_ch;
                buf[i--] = '0';
        }

        i++;

        return Enter_unsigned(0, i, buf, flg, wdth, pre, s);
}

