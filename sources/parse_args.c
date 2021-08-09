/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:18:19 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/08 23:23:40 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	*ft_is_inside_stack(t_stack *stack, int nbr)
{
	t_stack_node	*node;
	int				i;

	node = stack->head;
	i = 0;
	while (i < stack->length)
	{
		if (node->content == nbr)
			return (true);
		i++;
		node = node->next;
	}
	return (false);
}

static bool	parse_and_push(char *s, t_stack *stack)
{
	long	value;
	int		*content;
	int		i;

	content = (int *)malloc(sizeof(int));
	if (!content)
		return (false);
	if (s[0] == '-' || s[0] == '+')
		s++;
	//*value = ft_atol(s);
	if (value > MAX_INT_VALUE || value < MIN_INT_VALUE)
		return (false);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	*content = (int)value;
	if (ft_is_inside_stack(stack, *content))
		return (false);
	push(stack, content);
	return (true);
}

bool	**parse_unique_string(char *string, t_stack *stack)
{
	char	**words;
	int		size;
	int		i;

	words = ft_split(string, ' ');
	size = 0;
	i = 0;
	if (!words)
		return (false);
	while (words[size])
		size++;
	while (i < size)
	{
		if (!parse_and_push(words[i], stack))
			return (false);
		free(words[i]);
		i++;
	}
	free(words);
	return (true);
}

bool	parse_args(int size, char *words[], t_stack *stack)
{
	int	i;

	if (size == 1)
		return (parse_unique_string(words[1], stack));
	i = size;
	while (i > 0)
	{
		if (!parse_and_push(words[i], stack))
		{
			return (false);
		}
		i--;
	}
	return (true);
}
