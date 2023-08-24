#include "monty.h"

/**
 * push - push elemnt to the stack
 * @stack: the given stack
 * @line_num: number of lines
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_num)
{
	char *n = glob_helper.argument;

	if (is_digit(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (glob_helper.data == 1)
	{
		if (!add_node(stack, atoi(glob_helper.argument)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!queue_node(stack, atoi(glob_helper.argument)))
			exit(EXIT_FAILURE);
	}
}
