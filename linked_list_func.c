#include "monty.h"

/**
 * add_node - add a node to the stack stack_t
 * @stack: head of the stack
 * @n: num of new nodes
 * Return: ....
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	return (new);
}

/**
 * queue_node - add a node to a stack_t stack in queu_node
 * @stack: head of stack
 * @n: number of nodes
 * Return: ...
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;
	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}
	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}
	return (new);
}

/**
 * print_stack - print the content of the stack
 * @stack: the hesd of stack
 * Return: num of elemnts of the linked list
 */
size_t print_stack(const stack_t *stack)
{
	size_t s = 0;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		s++;
	}
	return (s);
}

/**
 * free_stack - frees the dlistint_t
 * @stack: head of the list
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
