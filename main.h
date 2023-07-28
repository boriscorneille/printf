#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* flags manager */
#define FG_MINUS 1
#define FG_PLUS 2
#define FG_ZERO 4
#define FG_HASH 8
#define FG_SPACE 16

/* size manager */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - structure Declaration
 * @frmt: The format specification
 * @kk: expected function
 */
struct frmt
{
	char frmt;
	int (*kk)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frmt frmt_t - structure Declaration
 *
 * @frmt: Definition format.
 * @frmt_t: expected function
 */
typedef struct frmt frmt_t;

int _printf(const char *format, ...);
int all_handle(const char *frmt, int *i,
va_list lst, char buf[], int flg, int wdth, int pre, int s);

/*________________All_functions________________________*/

/* funtion to console char and str */
int p_char(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_str(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_percent(va_list types, char buf[],
	int flg, int wdth, int pre, int s);

/* functions to console numbers */
int p_int(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_binary(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_unsigned(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_octal(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_hexdec(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
int p_hex_up(va_list types, char buf[],
	int flg, int wdth, int pre, int s);

int p_hexa(va_list types, char map_to[],
char buf[], int flg, char flg_ch, int wdth, int pre, int s);

/* function to console all non printable characters */
int pr_non_pr_able(va_list types, char buf[],
	int flg, int wdth, int pre, int s);

/* funcion to console all memory address */
int pr_pointer(va_list types, char buf[],
	int flg, int wdth, int pre, int s);
void p_buf(char buf[], int *buf_i);

/* funciotns to manage other specifiers */
int g_flg(const char *frmt, int *x);
int g_wdth(const char *frmt, int *x, va_list lst);
int g_pre(const char *frmt, int *x, va_list lst);
int g_s(const char *frmt, int *x);

/*function that console all str in rev*/
int p_rev(va_list types, char buf[],
	int flg, int wdth, int pre, int s);

/*function that console a str in rot 13*/
int p_rt13str(va_list types, char buf[],
	int flg, int wdth, int pre, int s);

/* width control manager*/
int all_handle_manager(char c, char buf[],
	int flg, int wdth, int pre, int s);
int Enter_num(int is_pos, int i, char buf[],
	int flg, int wdth, int pre, int s);
int Entered_num(int i, char buf[], int flg, int wdth, int pre,
	int len, char pdd, char ext_c);
int Entered_pointer(char buf[], int i, int len,
	int wdth, int flg, char pdd, char ext_c, int pd_stat);

int Enter_unsigned(int is_neg, int i, char buf[], int flg,
		int wdth, int pre, int s);

/*___________ utils _________________*/
int is_consolable(char);
int appending_hex_code(char, char[], int);
int is_digit(char);

long int convert_s_num(long int num, int s);
long int convert_s_unsigned(unsigned long int num, int s);
#endif
