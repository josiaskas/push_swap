/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions_by_chunks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/01 23:52:42 by jkasongo         ###   ########.fr       */
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

void	move_up_to_n(t_stack *a, t_stack *b, int max)
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
				do_ra(a);
			do_pb(a, b);
		}
		else
		{
			while (bottom_count--)
				do_rra(a);
			do_pb(a, b);
		}
	}
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
		move_up_to_n(a, b, chunks[i]);
		i++;
	}
	free(arr);
	free(chunks);
}
