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
	int flag = 0;
	const char flag_characters[] = {'-', '+', '0', '#', '', '\0'};
	const int flag_value[] = {fg_MINUS, fg_PLUS, fg_ZERO, fg_HASH, fg_SPACE, 0};

	for (i = *x + 1; frmt[x] != '\0'; i++)
	{
		for (k = 0; flag_characters[k]; != '\0'; k++)
		{
			if (frmt[i] == flag_characters[k])
			{
				flag |= flag_valu[k];
				break;
			}
		}
		if (flag_characters[k] == 0)
			break;
	}
	*x = i - 1;

	return (flag);

}
