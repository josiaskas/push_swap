/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:12:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/28 18:32:44 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorted_desc(t_stack *a)
{
	int	i;

	i = a->length;
	while (i > 1)
	{
		do_ra(a);
		i--;
	}
}

void	work_on_partitiotion(t_stack *a, t_stack *b, t_partition *part)
{
	int	median;
	int	*current_top_b;
	int	half;
	int *arr;
	//int	*arr_sliced;

	ft_putendl_fd(">>>reordering a partition", 1);
	while (part->size)
	{
		half = part->size / 2;
		arr = map_stack(b, do_nothing);
		//arr_sliced = ft_slice_int(arr, 0, part->size);
		median = 2;
		free(arr);
		//free(arr_sliced);
		ft_printf("size %d", part->size);
		while (half)
		{
			current_top_b = (int *)peak(b);
			if (*current_top_b >= median)
			{
				ft_printf("mediane %d", median);
				do_pa(a,b);
				part->size--;
				half--;
			}
			else
			{
				if (*current_top_b <= part->min)
				{
					while (part->down)
					{
						do_rrb(b);
						part->down--;
					}
				}
				else
				{
					do_rb(b);
					part->down++;
				}
			}
		}
	}
}

void	reorder_partitions(t_stack *a, t_stack *b, t_stack *partitions)
{
	int			*arr;
	int			*p_arr;
	t_partition	*part;

	ft_putendl_fd(">>>start reordering", 1);
	arr = map_stack(a, do_nothing);
	if(type_of_sort(arr, a->length) == 2)
		do_sa(a);
	free(arr);
	while (partitions->length)
	{
		ft_putendl_fd(">>>loop partitions start<<", 1);
		arr = map_stack(b, do_nothing);
		part = (t_partition *)pop(partitions);
		p_arr = ft_slice_int(arr, 0, part->size);
		work_on_partitiotion(a, b, part);
		free(arr);
		free(p_arr);
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
		sorted_desc(a);
		return ;
	}
	partitions = NULL;
	partitions = partitionate(a, b);
	//reorder_partitions(a, b, partitions);
	free_stack(partitions);
}
