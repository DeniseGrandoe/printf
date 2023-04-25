#include "main.h"

/**
 * get_flags - determines the flags of printf.
 *
 * @format: Formatted string argument that will be printed.
 * @i: pointer that ref arguments to be printed.
 *
 * Return: flags value
*/
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char flag_ch[] = {'+', '#', '0', '-', ' ', '\0'};
	const int flag_array[] = {F_PLUS, F_HASH, F_ZERO, F_MINUS, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; flag_ch[j] != '\0'; j++)
		{
			if (format[curr_i] == flag_ch[j])
			{
				flags |= flag_array[j];
				break;
			}
		}

		if (flag_ch[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
