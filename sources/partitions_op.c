/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:25:04 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_to_a(t_stack *a, t_stack *b, int max)
{
	int	top_count;
	int	bottom_count;

	while (1)
	{
		top_count = from_top_c(b, max);
		if (top_count == b->length)
			return ;
		bottom_count = from_bottom_c(b, max);
		if (top_count <= bottom_count)
		{
			while (top_count--)
				do_rb(b, false);
			do_pa(a, b, false);
		}
		else
		{
			while (bottom_count--)
				do_rrb(b, false);
			do_pa(a, b, false);
		}
	}
}

void	partionate_in_n_chunks_b(t_stack *a, t_stack *b, int n)
{
	int	*arr;
	int	*chunks;
	int	i;
	int	div;

	i = 0;
	arr = map_stack(b, do_nothing);
	heap_sort(arr, b->length);
	chunks = (int *)malloc(sizeof(int) * n);
	div = b->length / n;
	while (i < (n - 1))
	{
		chunks[i] = arr[div * (i + 1)];
		i++;
	}
	chunks[(n - 1)] = arr[b->length - 3];
	i = 0;
	while (i < n)
	{
		move_to_a(a, b, chunks[i]);
		i++;
	}
	free(arr);
	free(chunks);
}

void	partitionate_quarter(t_stack *a, t_stack *b)
{
	int	*arr_a;
	int	quarter;

	arr_a = NULL;
	while (a->length)
	{
		if (a->length < 3)
			break ;
		arr_a = map_stack(a, do_nothing);
		heap_sort(arr_a, a->length);
		quarter = arr_a[(a->length + 3) / 4];
		move_to_b(a, b, quarter);
		free(arr_a);
	}
	return ;
}

void	partitionate_quarter_to_a(t_stack *a, t_stack *b)
{
	int	*arr_a;
	int	quarter;

	arr_a = NULL;
	while (b->length)
	{
		if (b->length < 3)
			break ;
		arr_a = map_stack(b, do_nothing);
		heap_sort(arr_a, b->length);
		quarter = arr_a[(b->length + 3) / 4];
		move_to_a(a, b, quarter);
		free(arr_a);
	}
	return ;
}
