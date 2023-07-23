#include "main.h"

/**
 * g_width - Calc width for printing
 * @frmt: formatted string .
 * @x: list of arguments to be printed.
 * @lst: list of arguments.
 *
 * Return: width.
 */
int g_width(const char *frmt, int *x, va_list lst)
{
	int i;
	int w = 0;

	for (i = *x + 1; frmt[i] != '\0'; i++)
	{
		if (is_digit(frmt[i]))
		{
			w *= 10;
			w += frmt[i] - '0';
		}
		else if (frmt[i] == '*')
		{
			i++;
			w = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*x = i - 1;

	return (w);
}

