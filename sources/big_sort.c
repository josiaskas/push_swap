/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:12:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/29 16:18:37 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sorted_desc(t_stack *a, t_stack *b)
{
	while (a->length)
		do_pb(a,b);
	while (b->length)
	{
		do_rrb(b);
		do_pa(a,b);
	}
}

static void	work_on_partitiotion(t_stack *a, t_stack *b, t_partition *part)
{
	int	median;
	int	*current_top_b;
	int	half;
	int	*arr;
	int *arr_sliced;

	if (part->size == 1)
	{
		do_pa(a,b);
		part->size = 0;
		return ;
	}
	while (part->size)
	{
		half = part->size / 2;
		if (!half)
			half = 1;
		ft_printf(">>new half in partition : %d\n",half);
		arr = map_stack(b, do_nothing);
		arr_sliced = ft_slice_int(arr, 0, part->size);
		median = ft_find_median_value(arr_sliced, part->size);
		free(arr);
		free(arr_sliced);
		while (half)
		{
			current_top_b = (int *)peak(b);
			ft_printf("top: %d mid:%d ", *current_top_b, median);
			if ((*current_top_b > median))
			{
				half--;
				part->size--;
				do_pa(a, b);
			}
			else
			{
				do_rb(b);
				part->down++;
			}
			if (part->down == part->size)
			{
				while (part->down > 0)
				{
					do_rrb(b);
					part->down--;
				}
			}
			arr = NULL;
			arr_sliced = NULL;
		}
		part->max = median;
	}
}

void	reorder_partitions(t_stack *a, t_stack *b, t_stack *partitions)
{
	int			*arr;
	t_partition	*part;

	ft_putendl_fd(">>>start reordering", 1);
	arr = map_stack(a, do_nothing);
	if(type_of_sort(arr, a->length) == 2)
		do_sa(a);
	free(arr);
	while (partitions->length)
	{
		ft_putendl_fd(">>>poping partition<<\n\n", 1);
		part = (t_partition *)pop(partitions);
		(void)b;
		work_on_partitiotion(a, b, part);
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
		sorted_desc(a, b);
		return ;
	}
	partitions = NULL;
	partitions = partitionate(a, b);
	reorder_partitions(a, b, partitions);
	free_stack(partitions);
}
