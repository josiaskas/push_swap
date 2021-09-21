/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:35:11 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	free_them(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

static void	super_big(t_stack *a, t_stack *b)
{
	partitionate_mediane(a, b);
	partionate_in_n_chunks_b(a, b, 33);
	partionate_in_n_chunks(a, b, 55);
}

void	big_sort(t_stack *a, t_stack *b)
{
	if (a->length <= 50)
		partitionate_mediane(a, b);
	if (a->length <= 120)
		partitionate_quarter(a, b);
	else if (a->length <= 520)
	{
		partitionate_mediane(a, b);
		partionate_in_n_chunks_b(a, b, 11);
		partionate_in_n_chunks(a, b, 55);
	}
	else
		super_big(a, b);
	reorder_partitions(a, b);
	return ;
}

void	sort_selector(t_stack *a, t_stack *b)
{
	int	*arr_a;
	int	is_sorted;

	arr_a = map_stack(a, do_nothing);
	is_sorted = type_of_sort(arr_a, a->length);
	free(arr_a);
	if (is_sorted == 1)
		return ;
	else if (a->length == 1)
		return ;
	else if (a->length == 2)
		small_sort_two(a);
	else if (a->length == 3)
		small_sort3(a);
	else if (a->length == 4)
		small_sort4(a, b);
	else if (a->length == 5)
		small_sort5(a, b);
	else
	{
		if (is_sorted == 2)
			big_sort_it_asc(a, b);
		else
			big_sort(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack();
	stack_b = create_stack();
	if ((argc - 1) > 0)
	{
		if (!parse_args((argc - 1), argv, stack_a))
		{
			free_them(stack_a, stack_b);
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	sort_selector(stack_a, stack_b);
	free_them(stack_a, stack_b);
	return (0);
}
