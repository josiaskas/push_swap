/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:21:16 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/21 17:20:48 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort_it_asc(t_stack *a, t_stack *b)
{
	while (a->length)
		do_pb(a, b, false);
	while (b->length)
	{
		do_rrb(b, false);
		do_pa(a, b, false);
	}
}

void	small_sort_two(t_stack *a)
{
	int	*arr;

	arr = map_stack(a, do_nothing);
	if (type_of_sort(arr, a->length) == 2)
		do_sb(a, false);
	free(arr);
}

void	small_sort3(t_stack *a)
{
	int	*arr;

	if (a->length < 3)
	{
		small_sort_two(a);
		return ;
	}
	arr = map_stack(a, do_nothing);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		do_sa(a, false);
	else if ((arr[0] > arr[1]) && (arr[1] > arr[2]) && (arr[2] < arr[0]))
	{
		do_sa(a, false);
		do_rra(a, false);
	}
	else if ((arr[0] > arr[1]) && (arr[1] < arr[2]) && (arr[2] < arr[0]))
		do_ra(a, false);
	else if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[2] > arr[0]))
	{
		do_sa(a, false);
		do_ra(a, false);
	}
	else if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[2] < arr[0]))
		do_rra(a, false);
	free(arr);
}

void	small_sort4(t_stack *a, t_stack *b)
{
	int	*top_a;
	int	*arr;

	arr = map_stack(a, do_nothing);
	heap_sort(arr, a->length);
	top_a = (int *)peak(a);
	while (*top_a != arr[0])
	{
		do_ra(a, false);
		top_a = (int *)peak(a);
	}
	do_pb(a, b, false);
	small_sort3(a);
	do_pa(a, b, false);
	free(arr);
}
