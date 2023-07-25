#include "main.h"
/**
 * is_consolable - check if a character is consolable
 * @c: entered char to be evaluated.
 * Return: 1 if c is character, 0 else
 */
int is_consolable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * appending_hex_code -entering ascci in hex code to buffer memory
 * @buf: arrays of characters.
 * @i: index .
 * @asci_code: ASSCI CODE.
 * Return: always 3
 */
int appending_hex_code(char asci_code, char buf[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (asci_code < 0)
		asci_code *= -1;
	buf[i++] = '\\';
	buf[i++] = 'x';
	buf[i++] = map_to[asci_code / 16];
	buf[i] = map_to[asci_code % 16];
	return (3);
}
/**
 * is_digit - check if a characters is a digit
 * @c: characters to be cheched
 * Return: 1 if c is a digit, 0 else
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_s_num  locate a number to the specific size
 * @num: A given to be located.
 * @s: Number shows the located type
 * Return: located value of num
 */
long int convert_s_num(long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_s_unsigned - locate a number to the specified size
 * @num: number to be casted
 * @s: number shows the type to belocated
 * Return: located value of num
 */
long int convert_s_unsigned(unsigned long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
