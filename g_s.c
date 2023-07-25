#include "main.h"

/**
 * g_size - size to cast the argument
 * @frmt: formatted string
 * @x: list of arguments to be printed.
 * s: size
 * i: index
 * Return: precision.
 */
int g_s(const char *frmt, int *x)
{
	int i = *x + 1;
	int s = 0;

	if (frmt[i] == 'l')
		s = S_LONG;
	else if (frmt[i] == 'h')
		s = S_SHORT;

	if (s == 0)
		*x = i - 1;
	else
		*x = i;

	return (s);
}

