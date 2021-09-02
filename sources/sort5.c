/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:21:16 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/02 00:08:32 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_two(t_stack *a, t_stack *b, int arr[])
{
	int	*top_a;
	int	j;

	j = 0;
	while ((b->length < 2) && (j < 4))
	{
		top_a = (int *)peak(a);
		if (*top_a < arr[2])
			do_pb(a, b);
		else
		{
			do_ra(a);
			j++;
		}
	}
}

void	small_sort5(t_stack *a, t_stack *b)
{
	int	*arr;

	arr = map_stack(a, do_nothing);
	heap_sort(arr, a->length);
	push_two(a, b, arr);
	free(arr);
	small_sort3(a);
	arr = map_stack(b, do_nothing);
	if (type_of_sort(arr, b->length) == 1)
		do_sb(b);
	do_pa(a, b);
	do_pa(a, b);
	free(arr);
}
