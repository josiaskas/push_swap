/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:54:30 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/11 20:29:36 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	do_sa(t_stack *stack_a)
{
	bool	status;

	status = swap(stack_a);
	if (status)
		ft_putendl_fd("sa", 1);
	return (status);
}

bool	do_sb(t_stack *stack_b)
{
	bool	status;

	status = swap(stack_b);
	if (status)
		ft_putendl_fd("sb", 1);
	return (status);
}

bool	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	bool	status;

	status = false;
	if ((stack_a->length > 1) && (stack_b->length > 1))
	{
		if (swap(stack_a) && swap(stack_b))
		{
			ft_putendl_fd("ss", 1);
			status = true;
		}
	}
	else if ((stack_a->length > 1))
		status = do_sa(stack_a);
	else
		status = do_sb(stack_b);
	return (status);
}

bool	do_pa(t_stack *stack_a, t_stack *stack_b)
{
	bool	status;
	int		*content;

	status = false;
	content = 0;
	content = (int *)pop(stack_b);
	if (content)
		status = push(stack_a, content);
	if (status)
		ft_putendl_fd("pa", 1);
	return (status);
}

bool	do_pb(t_stack *stack_a, t_stack *stack_b)
{
	bool	status;
	int		*content;

	status = false;
	content = 0;
	content = (int *)pop(stack_a);
	if (content)
		status = push(stack_b, content);
	if (status)
		ft_putendl_fd("pb", 1);
	return (status);
}
