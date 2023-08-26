#include "monty.h"
#include <stdio.h>
void error_file(char *argv);
void error_usage(void);
int var = 0;

/**
 * main - check the code
 * @argc: args counter
 * @argv: number of argument passed
 * Return: Nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t len_buf = 0;
	char *str = NULL, *buffer = NULL;
	stack_t *stack = NULL;
	unsigned int line_num = 1;

	glob_helper.data = 1;
	if (argc != 2)
		error_usage();
	file = fopen(argv[1], "r");
	if (!file)
		error_file(argv[1]);
	while (getline(&buffer, &len_buf, file) != -1)
	{
		if (var)
			break;
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_num++;
			continue;
		}
		glob_helper.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_num);
		line_num++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * error_file - ...
 * @argv: ...
 * Return: Nothing
 */
void error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - ....
 * Return: Nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
