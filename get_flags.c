#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * @flg: character that holds the flag specifier
 * @p: pointer to the struct flags 
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char f, flags_t *p)
{
	int flg  = 0;

	switch (f)
	{
		case '0':
                        f_zero = 1;
                        flg = 1;
                        break;
                case '-':
                        f_minus = 1;
                        flg = 1;
		case '+':
			f_plus = 1;
			flg = 1;
			break;
		case ' ':
			f_space = 1;
			flg = 1;
			break;
		case '#':
			f_hash = 1;
			flg = 1;
			break;
	}

	return (flg);
}
