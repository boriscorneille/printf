#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number.
 * @types: va_list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2; // Initialize buffer index.
    unsigned long int num = va_arg(types, unsigned long int); // Get the unsigned number from va_list.

    num = convert_size_unsgnd(num, size); // Convert the number based on the size specifier.

    if (num == 0)
        buffer[i--] = '0'; // Special case for 0.

    buffer[BUFF_SIZE - 1] = '\0'; // Null-terminate the buffer.

    // Extract individual digits of the number and store them in the buffer.
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++; // Move the buffer index to the correct position.

    // Write the formatted output to the standard output.
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation.
 * @types: va_list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2; // Initialize buffer index.
    unsigned long int num = va_arg(types, unsigned long int); // Get the unsigned number from va_list.
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size); // Convert the number based on the size specifier.

    if (num == 0)
        buffer[i--] = '0'; // Special case for 0.

    buffer[BUFF_SIZE - 1] = '\0'; // Null-terminate the buffer.

    // Extract individual digits of the number and store them in the buffer.
    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    // Add '0' prefix if F_HASH flag is set and the number is not 0.
    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++; // Move the buffer index to the correct position.

    // Write the formatted output to the standard output.
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation.
 * @types: va_list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // Call print_hexa with lowercase hexadecimal digits mapping.
    return (print_hexa(types, "0123456789abcdef", buffer,
        flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation.
 * @types: va_list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // Call print_hexa with uppercase hexadecimal digits mapping.
    return (print_hexa(types, "0123456789ABCDEF", buffer,
        flags, 'X', width, precision, size));
}

/************** PRINT HEX NUMBER IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper case.
 * @types: va_list of arguments.
 * @map_to: Array of values to map the number to.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @flag_ch: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
    int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2; // Initialize buffer index.
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size); // Convert the number based on the size specifier.

    if (num == 0)
        buffer[i--] = '0'; // Special case for 0.

    buffer[BUFF_SIZE - 1] = '\0'; // Null-terminate the buffer.

    // Extract individual digits of the number and store them in the buffer.
    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    // Add '0x' or '0X' prefix if F_HASH flag is set and the number is not 0.
    if (flags & F_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++; // Move the buffer index to the correct position.

    // Write the formatted output to the standard output.
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
