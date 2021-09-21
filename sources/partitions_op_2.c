/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions_op_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:21:34 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	from_top_c(t_stack *a, int max)
{
	int	*arr;
	int	i;

	arr = map_stack(a, do_nothing);
	i = 0;
	while (i < a->length)
	{
		if (arr[i] <= max)
			break ;
		i++;
	}
	free(arr);
	return (i);
}

int	from_bottom_c(t_stack *a, int max)
{
	int	*arr;
	int	i;

	arr = map_stack(a, do_nothing);
	i = a->length - 1;
	while (i > 0)
	{
		if (arr[i] <= max)
			break ;
		i--;
	}
	free(arr);
	return (a->length - i);
}

void	move_to_b(t_stack *a, t_stack *b, int max)
{
	int	top_count;
	int	bottom_count;

	while (1)
	{
		top_count = from_top_c(a, max);
		if (top_count == a->length)
			return ;
		bottom_count = from_bottom_c(a, max);
		if (top_count <= bottom_count)
		{
			while (top_count--)
				do_ra(a, false);
			do_pb(a, b, false);
		}
		else
		{
			while (bottom_count--)
				do_rra(a, false);
			do_pb(a, b, false);
		}
	}
}

void	partitionate_mediane(t_stack *a, t_stack *b)
{
	int	*arr_a;
	int	median;

	arr_a = NULL;
	while (a->length)
	{
		if (a->length == 2)
			break ;
		arr_a = map_stack(a, do_nothing);
		median = ft_find_median_value(arr_a, a->length);
		move_to_b(a, b, median);
		free(arr_a);
	}
	return ;
}

void	partionate_in_n_chunks(t_stack *a, t_stack *b, int n)
{
	int	*arr;
	int	*chunks;
	int	i;
	int	div;

	i = 0;
	arr = map_stack(a, do_nothing);
	heap_sort(arr, a->length);
	chunks = (int *)malloc(sizeof(int) * n);
	div = a->length / n;
	while (i < (n - 1))
	{
		chunks[i] = arr[div * (i + 1)];
		i++;
	}
	chunks[(n - 1)] = arr[a->length - 3];
	i = 0;
	while (i < n)
	{
		move_to_b(a, b, chunks[i]);
		i++;
	}
	free(arr);
	free(chunks);
}
