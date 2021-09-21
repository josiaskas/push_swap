/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:15:37 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:29:07 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	do_ra(t_stack *stack_a, bool silent)
{
	bool	status;

	status = rotate(stack_a);
	if (status && !silent)
		ft_putendl_fd("ra", 1);
	return (status);
}

bool	do_rb(t_stack *stack_b, bool silent)
{
	bool	status;

	status = rotate(stack_b);
	if (status && !silent)
		ft_putendl_fd("rb", 1);
	return (status);
}

bool	do_rr(t_stack *stack_a, t_stack *stack_b, bool silent)
{
	bool	 status;

	status = false;
	if ((stack_a->length > 1) && (stack_b->length > 1))
	{
		if ((rotate(stack_a) && rotate(stack_b)) && !silent)
		{
			ft_putendl_fd("rr", 1);
			status = true;
		}
	}
	else if ((stack_a->length > 1))
		status = do_ra(stack_a, silent);
	else
		status = do_rb(stack_b, silent);
	return (status);
}
