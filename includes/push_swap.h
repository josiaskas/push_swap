/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:20:26 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/09 20:11:39 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "stack.h"

// size (number of args without the first one), args and the stack to push to
bool	parse_args(int size, char *words[], t_stack *stack);

// return the median of an array of int;
int		ft_find_median_value(int arr[], int n);

#endif
