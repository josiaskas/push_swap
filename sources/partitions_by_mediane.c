/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions_by_mediane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/01 22:08:57 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	move_part_to_b(int median, int half, t_stack *a, t_stack *b)
{
	int	*current_top_a;

	current_top_a = NULL;
	while (half)
	{
		current_top_a = (int *)peak(a);
		if (*current_top_a < median)
		{
			do_pb(a, b);
			half--;
		}
		else
			do_ra(a);
	}
	return (true);
}

void	partitionate(t_stack *a, t_stack *b)
{
	int		*arr_a;
	int		half;
	int		median;

	arr_a = NULL;
	while (a->length > 2)
	{
		arr_a = map_stack(a, do_nothing);
		half = (a->length) / 2;
		median = ft_find_median_value(arr_a, a->length);
		if (half == 0)
			half = 1;
		move_part_to_b(median, half, a, b);
		free(arr_a);
	}
	return ;
}
