#include "monty.h"

/**
 * is_digit - check if a string is digit
 * @string: string to be checked
 * Return: 1 , or 0 if it fieled
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if(isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
