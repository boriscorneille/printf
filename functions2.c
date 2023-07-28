#include "main.h"
#include "string.h"

/**
 * p_pointer - prints a pointer value.
 * @addrs: pointer to be printed.
 * Return: length of the printed pointer.
 */
int p_pointer(void *addrs)
{
    unsigned long num_addrs;
    char map_to[] = "0123456789abcdef";
    char buffer[BUFF_SIZE];
    int i;

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    num_addrs = (unsigned long)addrs;
    for (i = BUFF_SIZE - 2; num_addrs > 0; i--)
    {
        buffer[i] = map_to[num_addrs % 16];
        num_addrs /= 16;
    }
    buffer[i] = '\0';
    write(1, buffer, i + 1);

    return (i + 1);
}

/**
 * p_non_pr_able - prints non-printable characters.
 * @str: string to be printed.
 * Return: length of the printed string.
 */
int p_non_pr_able(char *str)
{
    int i;
    int offset;

    if (str == NULL)
        return (write(1, "(null)", 6));

    for (i = 0; str[i] != '\0'; i++)
    {
        if (is_consolable(str[i]))
            write(1, &str[i], 1);
        else
        {
            offset = appending_hex_code(str[i], setbuffer, i);
            write(1, buffer, offset);
        }
    }

    return (strlen(str));
}

/**
 * p_rev - prints a string in reverse.
 * @str: string to be reversed.
 * Return: length of the printed string.
 */
int p_rev(char *str)
{
    int i;

    if (str == NULL)
        return (write(1, ")Null(", 6));

    for (i = strlen(str) - 1; i >= 0; i--)
    {
        write(1, &str[i], 1);
    }

    return (strlen(str));
}

/**
 * p_rt13str - prints a ROT13 encrypted string.
 * @str: string to be encrypted.
 * Return: length of the printed string.
 */
int p_rt13str(char *str)
{
    char x;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    int i, j;

    if (str == NULL)
        return (write(1, "(AHYY)", 6));

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                break;
            }
        }
    }

    return (strlen(str));
}
