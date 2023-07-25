#include "main.h"

/*________________________ All_handle_manager_________________________*/
/**
 * all_handle_manager - console all strings
 * @c: all character types.
 * @buf: array to console output
 * @flg:  calc available flag.
 * @wdth: calc width.
 * @pre: precision specifier
 * @s: calc size specifier
 *
 * Return: calc number of chars console.
 */
int all_handle_manager(char c, char buf[],
	int flg, int wdth, int pre, int s)
{ 
	int x = 0;
	char pdd = ' ';

	UNUSED(pre);
	UNUSED(s);

	if (flg & F_ZERO)
		pdd = '0';

	buf[x++] = c;
	buf[x] = '\0';

	if (wdth > 1)
	{
		buf[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < wdth - 1; x++)
			buf[BUFF_SIZE - x - 2] = pdd;

		if (flg & F_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUFF_SIZE - x - 1], wdth - 1));
		else
			return (write(1, &buf[BUFF_SIZE - x - 1], wdth - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}

/*_________________________ Enter number __________________________*/
/**
 * Enter_number - console all number
 * @is_neg: list all args
 * @ind: char types.
 * @buf:  array to console print
 * @flg:  Calc available flag
 * @wdth: calc width.
 * @pre: specifier precision
 * @s: calc size
 * Return: number of chars printed.
 */int Enter_number(int is_negative, int i, char buf[],
	int flg, int wdth, int pre, int s)
{

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		pdd = '0';
	if (is_negative)
		ext_ch = '-';
	else if (flg & F_PLUS)
		ext_ch = '+';
	else if (flg & F_SPACE)
		ext_ch = ' ';

	return (Entered_num(i, buf, flg, wdth, pre,
		len, pdd, ext_ch));
}

/**
 * Entered_num  - enter all number using a bufffer
 * @i: Index for each num
 * @buf: memory buffer
 * @flg: enetred flags
 * @wdth: check width
 * @pre: check precision specifier
 * @len: check length
 * @pdd: check Pading char
 * @ext_c: check extra char
 *
 * Return: Number of console chars.
 */
int Entered_num(int i, char buf[], int flg, int wdth, int pre,
        int len, char pdd, char ext_c);
{
	int x, pd_stat = 1;

	if (pre == 0 && i == BUFF_SIZE - 2 && buf[i] == '0' && wdth == 0)
		return (0); 
	if (pre == 0 && i == BUFF_SIZE - 2 && buf[i] == '0')
		buf[i] = pdd = ' '; 
	if (pre > 0 && pre < len)
		pdd = ' ';
	while (pre > len)
		buf[--i] = '0', len++;
	if (ext_c != 0)
		len++;
	if (wdth > len)
	{
		for (x = 1; x < wdth - len + 1; x++)
			buf[x] = pdd;
		buf[x] = '\0';
		if (flg & F_MINUS && pdd == ' ')
		{
			if (ext_c)
				buf[--i] = ext_c;
			return (write(1, &buf[i], len) + write(1, &buf[1], x - 1));
		}
		else if (!(flg & F_MINUS) && pdd == ' ')
		{
			if (ext_c)
				buf[--i] = ext_c;
			return (write(1, &buf[1], x - 1) + write(1, &buf[i], len));
		}
		else if (!(flg & F_MINUS) && pdd == '0')
		{
			if (ext_c)
				buf[--pd_stat] = ext_c;
			return (write(1, &buf[pd_stat], x - pd_stat) +
				write(1, &buf[i], len - (1 - pd_stat)));
		}
	}
	if (ext_c)
		buf[--i] = ext_c;
	return (write(1, &buf[i], len));
}

/**
 * Enter_unsigned - Enter an unsigned number
 * @is_negative: checker for checking if the num is negative
 * @i: it's index
 * @buf: using array of chars
 * @flg: enter flag 
 * @wdth: check Width specifier
 * @pre: check Precision specifier
 * @s: check size specifier
 *
 * Return: Number of entered chars.
 */
int Enter_unsigned(int is_negative, int i, char buf[], int flg, int wdth, int pre, int s)
{
	int len = BUFF_SIZE - i - 1, x = 0;
	char pdd = ' ';

	UNUSED(is_negative);
	UNUSED(s);

	if (pre == 0 && i == BUFF_SIZE - 2 && buf[i] == '0')
		return (0);

	if (pre > 0 && pre < len)
		pdd = ' ';

	while (pre > len)
	{
		buf[--i] = '0';
		len++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		pdd = '0';

	if (wdth > len)
	{
		for (x = 0; x < wdth - len; x++)
			buf[x] = pdd;

		buf[x] = '\0';

		if (flg & F_MINUS) 
		{
			return (write(1, &buf[i], len) + write(1, &buf[0], x));
		}
		else 
		{
			return (write(1, &buf[0], x) + write(1, &buf[i], len));
		}
	}

	return (write(1, &buf[i], len));
}

/**
 * Entered_pointer - enter a memory address
 * @buf: arrays
 * @i: index
 * @len: check of number
 * @wdth: check width
 * @flg: check flags specifier
 * @pdd: checking a char representing the padding
 * @ext_c: checking a char representing other char
 * @pd_stat: checking index at which padding should start
 *
 * Return: Number of entered chars.
 */

int Entered_pointer(char buf[], int i, int len,
        int wdth, int flg, char pdd, char ext_c, int pd_stat);
{
	int x;

	if (wdth > len)
	{
		for (x = 3; x < wdth - len + 3; x++)
			buf[x] = pdd;
		buf[x] = '\0';
		if (flg & F_MINUS && pdd == ' ')
		{
			buf[--i] = 'x';
			buf[--i] = '0';
			if (ext_c)
				buf[--i] = ext_c;
			return (write(1, &buf[i], len) + write(1, &buf[3], x - 3));
		}
		else if (!(flg & F_MINUS) && pdd == ' ')
		{
			buf[--i] = 'x';
			buf[--i] = '0';
			if (ext_c)
				buf[--i] = ext_c;
			return (write(1, &buf[3], i - 3) + write(1, &buf[i], len));
		}
		else if (!(flg & F_MINUS) && pdd == '0')
		{
			if (ext_c)
				buf[--pd_stat] = ext_c;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[pd_stat], i - pd_stat) +
				write(1, &buf[i], len - (1 - pd_stat) - 2));
		}
	}
	buf[--i] = 'x';
	buf[--i] = '0';
	if (ext_c)
		buf[--i] = ext_c;
	return (write(1, &buf[i], BUFF_SIZE - i - 1));
}
