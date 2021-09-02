/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions_by_chunks_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/01 23:53:31 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_up_to_n2(t_stack *a, t_stack *b, int max)
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
				do_rb(b);
			do_pa(a, b);
		}
		else
		{
			while (bottom_count--)
				do_rrb(b);
			do_pa(a, b);
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
		move_up_to_n2(a, b, chunks[i]);
		i++;
	}
	free(arr);
	free(chunks);
}
