/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:09:41 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/08 14:34:00 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->length = 0;
	stack->head = 0;
	stack->bottom = 0;
	stack->current = 0;
	return (stack);
}

int	*push(t_stack *stack, int value)
{
	t_stack_node	*node;

	if (stack == 0)
		return (0);
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == 0)
		return (0);
	node->value = value;
	if (stack->length == 0)
	{
		stack->bottom = node;
		stack->length = 1;
	}
	else
	{
		node->next = stack->head;
		stack->bottom->next = node;
		stack->length++;
	}
	stack->head = node;
	return (1);
}

int	pop(t_stack *stack)
{
	t_stack_node	*node;
	int				value;

	if (stack == 0)
		return (MIN_VALUE);
	if (stack->length == 0)
		return (MIN_VALUE);
	node = stack->head;
	if (stack->length == 1)
	{
		value = node->value;
		stack->bottom = 0;
		stack->head = 0;
	}
	if (stack->length > 1)
	{	
		value = node->value;
		stack->bottom->next = stack->head->next;
		stack->head = stack->head->next;
	}
	stack->length--;
	free(node);
	return (value);
}

int	peak(t_stack *stack)
{
	int				value;

	if (stack == 0)
		return (MIN_VALUE);
	if (stack->length == 0)
		return (MIN_VALUE);
	value = stack->head->value;
	return (value);
}

int	is_empty(t_stack *stack)
{
	int				value;

	if (stack == 0)
		return (MIN_VALUE);
	if (stack->length == 0)
		return (1);
	return (0);
}
