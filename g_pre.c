#include "main.h"
/**
 * g_pre - precision for printing
 * @frmt : formatted strings
 * @x: args to be printed
 * @lst: list of args
 *
 * Return: precision
 */
int g_pre(const char *frmt, int *x, va_list lst)
{
int i = *x + 1;
int pre = -1;

if (frmt[i] != '.')
	return (pre);
pre = 0;
for (i += 1; frmt[i] != '\0'; i++)
{
	if (is_digit(frmt[i]))
	{
		pre *= 10;
		pre += frmt[i] - '0';
	}
	else if (frmt[i] == '*')
	{
		i++;
		pre = va_arg(lst, int);
		break;
	}
	else
		break;
}
*x = i - 1;
return (pre);
}
