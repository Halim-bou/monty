#include "monty.h"

/**
 * swap - function that swap data from the top to the next
 * @stack: the given stack
 * @line_num: number of line
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = NULL;
	int n = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	n = ptr->n;
	ptr->n = n;
	ptr->n = ptr->next->n;
	ptr->next->n = n;
}
