/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:21:16 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/31 19:42:16 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort_it_asc(t_stack *a, t_stack *b)
{
	while (a->length)
		do_pb(a, b);
	while (b->length)
	{
		do_rrb(b);
		do_pa(a, b);
	}
}

void	small_sort_two(t_stack *a)
{
	int	*arr;

	arr = map_stack(a, do_nothing);
	if (type_of_sort(arr, a->length) == 2)
		do_sb(a);
	free(arr);
}

void	small_sort3(t_stack *a)
{
	int	*arr;

	if (a->length < 3)
	{
		small_sort_two(a);
		return;
	}
	arr = map_stack(a, do_nothing);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		do_sa(a);
	else if ((arr[0] > arr[1]) && (arr[1] > arr[2]) && (arr[2] < arr[0]))
	{
		do_sa(a);
		do_rra(a);
	}
	else if ((arr[0] > arr[1]) && (arr[1] < arr[2]) && (arr[2] < arr[0]))
		do_ra(a);
	else if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[2] > arr[0]))
	{
		do_sa(a);
		do_ra(a);
	}
	else if((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[2] < arr[0]))
			do_rra(a);
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
		do_ra(a);
		top_a = (int *)peak(a);
	}
	do_pb(a,b);
	small_sort3(a);
	do_pa(a,b);
	free(arr);
}

void	small_sort5(t_stack *a, t_stack *b)
{
	int	*top_a;
	int	*arr;
	int	j;

	arr = map_stack(a, do_nothing);
	heap_sort(arr, a->length);
	j = 0;
	while ((b->length < 2) && (j < 4))
	{
		top_a = (int *)peak(a);
		if (*top_a < arr[2])
			do_pb(a,b);
		else
		{
			do_ra(a);
			j++;
		}
	}
	free(arr);
	small_sort3(a);
	arr = map_stack(b, do_nothing);
	if (type_of_sort(arr, b->length) == 1)
		do_sb(b);
	do_pa(a,b);
	do_pa(a,b);
	free(arr);
}
