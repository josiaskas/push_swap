/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/20 14:35:07 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*data;

	stack_a = create_stack();
	stack_b = create_stack();
	if ((argc - 1) > 0)
	{
		if (!parse_args((argc - 1), argv, stack_a))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	print_stacks(stack_a, stack_b);
	move_all_to_b(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
