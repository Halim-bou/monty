#include "monty.h"

/**
 * pop - func that pop the first elemnt in the stack
 * @stack: the given stack
 * @line_num: line number
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
