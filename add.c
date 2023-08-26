#include "monty.h"

/**
 * add - func that add the first two nodes of the stack
 * @stack: the given stack
 * @line_num: line number
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_num)
{
	int res = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	res = (*stack)->next->n + (*stack)->n;
	pop(stack, line_num);
	(*stack)->n = res;
}
