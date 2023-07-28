#include "main.h"
/**
 * all_ handle - It provides output based on input type
 * @frmt: Analyser of the string as an args
 * @lst: list of args
 * @i: index
 * @buf: memory of array buffer
 * @flg: Calc flags
 * @wdth: calc width.
 * @pre: calc precision
 * @s: calc Size
 * Return: 1 or 2;
 */
int all_handle(const char *frmt, int *i, va_list lst, char buf[],
	int flg, int wdth, int pre, int s)
{
	int x, l = 0, pr_char = -1;
	frmt_t frmt_type[] = {
		{'c', p_char}, {'s', p_str}, {'%', p_percent},
		{'i', p_int}, {'d', p_int}, {'b', p_binary},
		{'u', p_unsigned}, {'o', p_octal}, {'x', p_hexdec},
		{'X', p_hex_up}, {'p', pr_pointer}, {'S', pr_non_pr_able},
		{'r', p_rev}, {'R', p_rt13str}, {'\0', NULL}
	};
for (x = 0; frmt_type[x].frmt != '\0'; x++)
{
if (frmt[*i] == frmt_type[x].frmt)
{
	return (frmt_type[x].kk(lst, buf, flg, wdth, pre, s));
}
}
if (frmt_type[x].frmt == '\0')
{
if (frmt[*i] == '\0')
	return (-1);
l += write(1, "%%", 1);
if (frmt[*i - 1] == ' ')
	l += write(1, " ", 1);
else if (wdth)
{
--(*i);
while (frmt[*i] != ' ' && frmt[*i] != '%')
	--(*i);
if (frmt[*i] == ' ')
{
--(*i);
}
return (1);
}
l += write(1, &frmt[*i], 1);
return (l);
}
return (pr_char);
}

