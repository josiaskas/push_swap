/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/11 20:38:29 by jkasongo         ###   ########.fr       */
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
	do_pb(stack_a, stack_b);
	do_rrr(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	while (stack_a->length)
	{
		data = (int *)pop(stack_a);
		// ft_printf("le nombre a pop : %d\n", *data);
		free(data);
	}
	free(stack_a);
	return (0);
}
