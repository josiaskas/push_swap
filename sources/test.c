/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/28 17:30:49 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	free_them(t_stack *a, t_stack *b, t_stack *partitons)
{
	free_stack(a);
	free_stack(partitons);
	free_stack(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*partitions;

	stack_a = create_stack();
	stack_b = create_stack();
	partitions = NULL;
	if ((argc - 1) > 0)
	{
		if (!parse_args((argc - 1), argv, stack_a))
		{
			free_them(stack_a, stack_b, partitions);
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	print_stacks(stack_a, stack_b);
	//partitions = partitionate(stack_a, stack_b);
	big_sort(stack_a,stack_b);
	print_stacks(stack_a, stack_b);
	free_them(stack_a, stack_b, partitions);
	return (0);
}
