/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/11 18:40:45 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	apply(void *content, int index)
{
	int	value;
	int	*data;

	(void)index;
	data = (int *)content;
	value = *data;
	return (value);
}

int	main(int argc, char *argv[])
{
	t_stack			*pile_a;
	int				*nbrs;
	int				mediane;
	int				*data;

	pile_a = create_stack();
	if ((argc - 1) > 0)
	{
		if (!parse_args((argc - 1), argv, pile_a))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	nbrs = map_stack(pile_a, apply);
	mediane = type_of_sort(nbrs, pile_a->length);
	ft_printf("le type de sort est %d\n", mediane);
	mediane = ft_find_median_value(nbrs, pile_a->length);
	ft_printf("la mediane est %d\n", mediane);
	while (pile_a->length)
	{
		data = (int *)pop(pile_a);
		ft_printf("le nombre a pop : %d\n", *data);
		free(data);
	}
	free(pile_a);
	return (0);
}
