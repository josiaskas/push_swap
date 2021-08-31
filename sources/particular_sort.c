/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:21:16 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/30 12:28:18 by jkasongo         ###   ########.fr       */
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
