/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/20 15:12:41 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	moving_to_b(t_stack *a, t_stack *b, int top_a)
{
	int *current_top_b;

	current_top_b = &top_a;
	if (b->length)
		current_top_b = (int *)peak(b);
	do_pb(a, b);
	if (top_a < *current_top_b)
		do_sb(b);
	return (true);
}

bool	move_all_to_b(t_stack *a, t_stack *b)
{
	int	*arr_a;
	int	median;
	int	half;
	int *current_top_a;

	while (a->length > 2)
	{
		half = (a->length) / 2;
		arr_a = map_stack(a, do_nothing);
		median = ft_find_median_value(arr_a, a->length);
		if (half == 0)
			moving_to_b(a, b, arr_a[0]);
		while (half)
		{
			current_top_a = (int *)peak(a);
			if (*current_top_a <= median)
			{
				moving_to_b(a, b, *current_top_a);
				half--;
			}
			else
				do_ra(a);
		}
	}
	return (true);
}


