/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/09 17:03:36 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*pile_a;
	int		*data;

	pile_a = create_stack();
	if ((argc - 1) > 0)
	{
		if (!parse_args((argc - 1), argv, pile_a))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	data = 0;
	while (pile_a->length)
	{
		data = (int *)pop(pile_a);
		ft_printf("le nombre a pop : %d\n", *data);
		free(data);
	}
	free(pile_a);
	return (0);
}
