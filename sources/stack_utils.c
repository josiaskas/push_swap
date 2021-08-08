/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:35:03 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/08 16:10:35 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	swap(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack == 0)
		return (0);
	if (stack->length <= 1)
		return (0);
	first = stack->head;
	second = first->next;
	stack->head = second;
	first->next = second->next;
	second->next = first;
	if (stack->length == 2)
		stack->bottom = first;
	return (1);
}

int	rotate(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack == 0)
		return (0);
	if (stack->length <= 1)
		return (0);
	if (stack->length == 2)
		return (swap(stack));
	first = stack->head;
	second = first->next;
	stack->head = second;
	stack->bottom = first;
	return (1);
}

int	reverse_rotate(t_stack *stack)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if (stack == 0)
		return (0);
	if (stack->length <= 1)
		return (0);
	if (stack->length == 2)
		return (swap(stack));
	last = stack->bottom;
	before_last = stack->head;
	while (before_last->next != last)
		before_last = before_last->next;
	stack->bottom = before_last;
	stack->head = last;
	return (1);
}

int	start_iteration(t_stack *stack)
{
	if (stack == 0)
		return (0);
	stack->current = 0;
}

t_stack_node	*get_next(t_stack *stack)
{
	int				i;
	t_stack_node	*node;

	i = 0;
	node = stack->head;
	if (stack == 0)
		return (0);
	while ((i <= stack->length) && (i <= stack->current))
	{
		node = node->next;
		i++;
	}
	return (node);
}
