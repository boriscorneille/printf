#include "main.h"
/**
 * g_flag - calculate available flags
 * @frmt: formatted string
 * @x: take a parameter
 * Return: flag
 */
int g_flg(const char *frmt, int *x)
{

	int k, i;
	int flg = 0;
	const char flag_characters[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flg_val[] = {FG_MINUS, FG_PLUS, FG_ZERO, FG_HASH, FG_SPACE, 0};

	for (i = *x + 1; frmt[i] != '\0'; i++)
	{
		for (k = 0; flag_characters[k] != '\0'; k++)
		{
			if (frmt[i] == flag_characters[k])
			{
				flg |= flg_val[k];
				break;
			}
		}
		if (flag_characters[k] == 0)
			break;
	}
	*x = i - 1;

	return (flg);

}
