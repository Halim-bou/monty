#include "maonty.h"

/**
 * pall - print the stack
 * @stack: the stack given
 * @line_num: num of lines
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	print_stack(*stack);
}
