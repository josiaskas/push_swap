/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:21:09 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/19 22:40:43 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	do_nothing(void *content, int index)
{
	int	value;
	int	*data;

	(void)index;
	data = (int *)content;
	value = *data;
	return (value);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	*content_a;
	int	*content_b;
	int	i;

	size = stack_a->length;
	i = 0;
	if (size < stack_b->length)
		size = stack_b->length;
	content_a = map_stack(stack_a, do_nothing);
	content_b = map_stack(stack_b, do_nothing);
	ft_putendl_fd("A	|	B\n", 1);
	while (i < size)
	{
		if ((i < stack_b->length) && (i < stack_a->length))
			ft_printf("%d	|	%d\n", content_a[i], content_b[i]);
		else if (i < stack_a->length)
			ft_printf("%d	|	\n", content_a[i]);
		else
			ft_printf("	|	%d\n", content_b[i]);
		i++;
	}
	ft_putendl_fd("---	|	---", 1);
	free(content_a);
	free(content_b);
}
