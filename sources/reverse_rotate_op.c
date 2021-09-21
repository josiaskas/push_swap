/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:33:30 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:27:40 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	do_rra(t_stack *stack_a, bool silent)
{
	bool	status;

	status = reverse_rotate(stack_a);
	if (status && !silent)
		ft_putendl_fd("rra", 1);
	return (status);
}

bool	do_rrb(t_stack *stack_b, bool silent)
{
	bool	status;

	status = reverse_rotate(stack_b);
	if (status && !silent)
		ft_putendl_fd("rrb", 1);
	return (status);
}

bool	do_rrr(t_stack *stack_a, t_stack *stack_b, bool silent)
{
	bool	 status;

	status = false;
	if ((stack_a->length > 1) && (stack_b->length > 1))
	{
		if ((reverse_rotate(stack_a) && reverse_rotate(stack_b)) && !silent)
		{
			ft_putendl_fd("rrr", 1);
			status = true;
		}
	}
	else if ((stack_a->length > 1))
		status = do_ra(stack_a, silent);
	else
		status = do_rb(stack_b, silent);
	return (status);
}
