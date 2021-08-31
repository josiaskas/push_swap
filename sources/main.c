/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/31 19:43:51 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	free_them(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	big_sort(t_stack *a, t_stack *b)
{
	int *arr_a;
	int is_sorted;

	arr_a = map_stack(a, do_nothing);
	is_sorted = type_of_sort(arr_a, a->length);
	free(arr_a);
	if (is_sorted == 1)
		return;
	if (is_sorted == 2)
	{
		big_sort_it_asc(a, b);
		return;
	}
	if (a->length <= 100)
		partitionate(a, b);
	else if (a->length <= 300)
		partionate_in_n_chunks(a, b, 8);
	else if (a->length <= 500)
		partionate_in_n_chunks(a, b, 12);
	else
		partionate_in_n_chunks(a, b, (a->length / 50));
	reorder_partitions(a, b);
	return;
}

void	sort_selector(t_stack *a, t_stack *b)
{
	if (a->length == 1)
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
		big_sort(a,b);
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
