/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/26 18:13:57 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	moving_to_b(t_stack *a, t_stack *b, int top_a)
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

static void add_partition(t_stack *partions, int median, int size)
{
	t_partition *part;

	part = (t_partition *)malloc(sizeof(t_partition));
	part->current_median = median;
	part->size = size;
	part->down = 0;
	push(partions, part);
	ft_printf("partition %d taille %d\n", partions->length, part->size);
}

static bool	move_part_to_b(t_stack *partions, int median, int half, t_stack *a, t_stack *b)
{
	int	*current_top_a;

	add_partition(partions, median, half);
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
	return (true);
}

t_stack	*partitionate(t_stack *a, t_stack *b)
{
	t_stack	*partions;
	int		*arr_a;
	int		half;
	int		median;

	partions = create_stack();
	while (a->length > 2)
	{
		arr_a = map_stack(a, do_nothing);
		half = (a->length) / 2;
		median = ft_find_median_value(arr_a, a->length);
		if (half == 0)
		{
			add_partition(partions, median, 1);
			moving_to_b(a, b, arr_a[0]);
		}
		move_part_to_b(partions, median, half, a, b);
	}
	return (partions);
}