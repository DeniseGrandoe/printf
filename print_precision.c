#include "main.h"

/**
 * get_precision - determines the precision for printf.
 *
 * @format: Formatted string argument that will be printed.
 * @i: pointer that ref arguments to be printed.
 * @list: list of argument in printf.
 *
 * Return: precision value
*/

int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = curr_i - 1;

	return (precision);
}
