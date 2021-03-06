/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:12:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:25:06 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	from_top_count(t_stack *b)
{
	int	*arr;
	int	i;
	int	*ordored;
	int	max;

	arr = map_stack(b, do_nothing);
	ordored = map_stack(b, do_nothing);
	heap_sort(ordored, b->length);
	max = ordored[b->length - 1];
	i = 0;
	while (i < b->length)
	{
		if (arr[i] == max)
			break ;
		i++;
	}
	free(arr);
	free(ordored);
	return (i);
}

static int	from_bottom_count(t_stack *b)
{
	int	*arr;
	int	i;
	int	*ordored;
	int	max;

	arr = map_stack(b, do_nothing);
	ordored = map_stack(b, do_nothing);
	heap_sort(ordored, b->length);
	max = ordored[b->length - 1];
	i = b->length - 1;
	while (i > 0)
	{
		if (arr[i] == max)
			break ;
		i--;
	}
	free(arr);
	free(ordored);
	return (b->length - i);
}

static void	move_one(t_stack *a, t_stack *b)
{
	int		top_count;
	int		bottom_count;

	top_count = from_top_count(b);
	bottom_count = from_bottom_count(b);
	if (top_count <= bottom_count)
	{
		while (top_count)
		{
			do_rb(b, false);
			top_count--;
		}
		do_pa(a, b, false);
	}
	else
	{
		while (bottom_count)
		{
			do_rrb(b, false);
			bottom_count--;
		}
		do_pa(a, b, false);
	}
}

void	reorder_partitions(t_stack *a, t_stack *b)
{
	int	*arr_a;

	arr_a = map_stack(a, do_nothing);
	if (type_of_sort(arr_a, a->length) != 1)
		do_sa(a, false);
	free(arr_a);
	while (b->length)
		move_one(a, b);
}
