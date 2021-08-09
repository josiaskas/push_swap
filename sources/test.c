/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:25:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/09 14:50:23 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*pile;
	int		*data;

	pile = create_stack();
	if ((argc - 1) > 0)
	{
		if (!parse_args((argc - 1), argv, pile))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	data = 0;
	while (pile->length)
	{
		data = (int *)pop(pile);
		ft_printf("le nombre a pop : %d\n", *data);
		free(data);
	}
	free(pile);
	return (0);
}
