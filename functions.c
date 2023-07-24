#include "main.h"

/**
 * print_unsigned - Print an unsigned integer number
 * @types: va_list containing the argument to print
 * @buffer: Buffer to store the resulting string
 * @flags: Formatting flags
 * @width: Minimum field width
 * @precision: Minimum number of digits to be printed
 * @size: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: The number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[i--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0) {
                buffer[i--] = (num % 10) + '0';
                num /= 10;
        }

        i++;

        return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/**
 * print_octal - Print an unsigned number in octal format
 * @types: va_list containing the argument to print
 * @buffer: Buffer to store the resulting string
 * @flags: Formatting flags
 * @width: Minimum field width
 * @precision: Minimum number of digits to be printed
 * @size: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: The number of characters printed
 */
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(width);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[i--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0) {
                buffer[i--] = (num % 8) + '0';
                num /= 8;
        }

        if (flags & F_HASH && init_num != 0)
                buffer[i--] = '0';

        i++;

        return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/**
 * print_hexadecimal - Print an unsigned number in hexadecimal format (lowercase)
 * @types: va_list containing the argument to print
 * @buffer: Buffer to store the resulting string
 * @flags: Formatting flags
 * @width: Minimum field width
 * @precision: Minimum number of digits to be printed
 * @size: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: The number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return print_hexa(types, "0123456789abcdef", buffer,
                flags, 'x', width, precision, size);
}

/**
 * print_hexa_upper - Print an unsigned number in hexadecimal format (uppercase)
 * @types: va_list containing the argument to print
 * @buffer: Buffer to store the resulting string
 * @flags: Formatting flags
 * @width: Minimum field width
 * @precision: Minimum number of digits to be printed
 * @size: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: The number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return print_hexa(types, "0123456789ABCDEF", buffer,
                flags, 'X', width, precision, size);
}

/**
 * print_hexa - Print an unsigned number in hexadecimal format
 * @types: va_list containing the argument to print
 * @map_to: Mapping of digits for hexadecimal conversion
 * @buffer: Buffer to store the resulting string
 * @flags: Formatting flags
 * @flag_ch: Character for the hexadecimal flag (e.g., 'x' or 'X')
 * @width: Minimum field width
 * @precision: Minimum number of digits to be printed
 * @size: Size modifier (e.g., 'h', 'l', 'z', 'j', 't')
 *
 * Return: The number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(width);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[i--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0) {
                buffer[i--] = map_to[num % 16];
                num /= 16;
        }

        if (flags & F_HASH && init_num != 0) {
                buffer[i--] = flag_ch;
                buffer[i--] = '0';
        }

        i++;

        return write_unsgnd(0, i, buffer, flags, width, precision, size);
}
