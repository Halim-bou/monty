#include "monty.h"

/**
 * opcode - func for ranning builtins
 * @stack: the given stack
 * @str: compered string
 * @line_num: ...
 * Return: Nothing
 */
void opcode(stack_t **stack, char *str, unsigned int line_num)
{
	int i = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	if (!strcmp(str, "stack"))
	{
		glob_helper.data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		glob_helper.data = 0;
		return;
	}
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}
