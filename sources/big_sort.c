/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:12:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/31 02:16:29 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_a(t_stack *a, t_stack *b, t_partition *part)
{
	int	*current_b;
	int	*current_a;

	current_b = (int *)peak(b);
	current_a = (int *)peak(a);
	if (*current_a < *current_b)
	{
		do_ra(a);
		do_pa(a, b);
		do_rra(a);
	}
	else
		do_pa(a, b);
	part->size = part->size - 1;
}

void	move_long(t_stack *a, t_stack *b, t_partition *part, int med, bool last)
{
	int		*current_nbr;
	int		half;

	current_nbr = (int *)peak(b);
	half = part->size / 2;
	while (*current_nbr >= part->min)
	{
		if (*current_nbr > med)
			push_to_a(a,b,part);
		if (last && (*current_nbr == med))
			push_to_a(a, b, part);
		else
		{
			do_rb(b);
			//ft_printf("--mediane %d, val:%d, down: %d min:%d size:%d , half: %d\n", med, *current_nbr, part->down, part->min,part->size,half);
			part->down++;
		}
		current_nbr = (int *)peak(b);
		if (part->down > (half+1))
			return ;
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
		push_to_a(a, b, part);
	}
}

void	move_short3(t_stack *a, t_stack *b, t_partition *part, int arr[])
{
	int	*current_nbr;
	int	type_sort;

	type_sort = type_of_sort(arr, part->size);
	if (type_sort == 1)
	{
		do_sb(b);
		push_to_a(a, b, part);
		do_sb(b);
		push_to_a(a, b, part);
		push_to_a(a, b, part);
	}
	else if (type_sort == 2)
		while (part->size)
			push_to_a(a, b, part);
	else
	{
		heap_sort(arr, part->size);
		current_nbr = (int *)peak(b);
		if (*current_nbr == arr[2])
			push_to_a(a, b, part);
		else if(*current_nbr == arr[1])
			push_to_a(a, b, part);
		else
		{
			do_sb(b);
			push_to_a(a, b, part);
		}

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
		// else if (part->size == 3)
		// 	move_short3(a, b, part, arr_sliced);
		else
		{
			median = ft_find_median_value(arr_sliced, part->size);
			move_long(a, b, part, median, last);
			if (part->down && !last)
			{
				while (part->down > 0)
				{
					do_rrb(b);
					part->down--;
				}
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
	int		i;

	i = 0;
	while (true)
	{
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
		partitions = partitionate(a, b);
		reorder_partitions(a, b, partitions);
		free_stack(partitions);
		i++;
	}
	return ;
}
