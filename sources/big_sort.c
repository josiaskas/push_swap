/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:12:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/30 12:23:02 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_long(t_stack *a, t_stack *b, t_partition *part, int median)
{
	int	*current_nbr;

	current_nbr = (int *)peak(b);
	if ((*current_nbr == part->min) && (part->size > 2))
	{
		do_rb(b);
		part->down++;
		current_nbr = (int *)peak(b);
	}
	while (current_nbr && ((*current_nbr) > part->min))
	{
		if (*current_nbr > median)
		{
			do_pa(a, b);
			part->size--;
		}
		else
		{
			do_rb(b);
			part->down++;
		}
		current_nbr = (int *)peak(b);
	}
}

static void move_short(t_stack *a, t_stack *b, t_partition *part, int arr[])
{
	if (part->size == 1)
	{
		do_pa(a, b);
		part->size--;
		return;
	}
	if (type_of_sort(arr, part->size) == 1)
		do_sb(b);
	while (part->size)
	{
		do_pa(a, b);
		part->size--;
	}
}

static void move_back(t_stack *a, t_stack *b, t_partition *part, bool last)
{
	int	median;
	int	*arr;
	int	*arr_sliced;

	while (part->size)
	{
		arr = map_stack(b, do_nothing);
		arr_sliced = ft_slice_int(arr, 0, part->size);
		if (part->size <= 2)
			move_short(a, b, part, arr_sliced);
		else
		{
			median = ft_find_median_value(arr_sliced, part->size);
			move_long(a, b, part, median);
			if (part->down && !last)
			{
				while (part->down--)
					do_rrb(b);
			}
		}
		free(arr);
		free(arr_sliced);
	}
}

static void	reorder_partitions(t_stack *a, t_stack *b, t_stack *partitions)
{
	int			*arr;
	t_partition	*part;
	bool		last;

	arr = map_stack(a, do_nothing);
	if(type_of_sort(arr, a->length) == 2)
		do_sa(a);
	free(arr);
	while (partitions->length)
	{
		last = false;
		if (partitions->length == 1)
			last = true;
		part = (t_partition *)pop(partitions);
		(void)b;
		move_back(a, b, part,last);
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	int		*arr_a;
	t_stack	*partitions;
	int		is_sorted;

	arr_a = map_stack(a, do_nothing);
	is_sorted = type_of_sort(arr_a, a->length);
	free(arr_a);
	if (is_sorted == 1)
		return ;
	if (is_sorted == 2)
	{
		big_sort_it_asc(a, b);
		return ;
	}
	partitions = NULL;
	partitions = partitionate(a, b);
	reorder_partitions(a, b, partitions);
	free_stack(partitions);
}
