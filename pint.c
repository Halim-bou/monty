#include "monty.h"

/**
 * pint - function that print the a value from the top of stack
 * @stack: the given stack
 * @line_num: line number
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
