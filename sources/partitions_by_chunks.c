/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions_by_chunks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:45:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/31 14:35:48 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_b(t_stack *a, t_stack *b)
{
	int	*arr;
	int	*current_b;
	int	min;

	if (b->length > 2)
	{
		arr = map_stack(b, do_nothing);
		heap_sort(arr, b->length);
		min = arr[0];
		current_b = (int *)peak(b);
		while (*current_b > min)
		{
			do_rb(b);
			current_b = (int *)peak(b);
		}
	}
	do_pb(a, b);
}

static int	from_top_count(t_stack *a, int max)
{
	int	*arr;
	int	i;

	arr = map_stack(a, do_nothing);
	i = 0;
	while (i < a->length)
	{
		if (arr[i] <= max)
			break;
		i++;
	}
	free(arr);
	return (i);
}

static int	from_bottom_count(t_stack *a, int max)
{
	int	*arr;
	int	i;

	arr = map_stack(a, do_nothing);
	i = a->length - 1;
	while (i > 0)
	{
		if (arr[i] <= max)
			break;
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
		top_count = from_top_count(a, max);
		if (top_count == a->length)
			return;
		bottom_count = from_bottom_count(a, max);
		if (top_count <= bottom_count)
		{
			while (top_count)
			{
				do_ra(a);
				top_count--;
			}
			push_to_b(a, b);
		}
		else
		{
			while (bottom_count)
			{
				do_rra(a);
				bottom_count--;
			}
			push_to_b(a, b);
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
		move_up_to_n(a,b, chunks[i]);
		i++;
	}
	free(chunks);
	(void)b;
}
