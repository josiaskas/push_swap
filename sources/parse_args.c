/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:18:19 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/02 00:21:34 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_is_inside_stack(t_stack *stack, int nbr)
{
	t_stack_node	*node;
	int				i;
	int				*value;

	node = stack->head;
	i = 0;
	while (i < stack->length)
	{
		value = (int *)node->content;
		if (*value == nbr)
			return (true);
		i++;
		node = node->next;
	}
	return (false);
}

static bool	parse_int(char *s, int *content)
{
	long	value;
	int		i;

	value = ft_atol(s);
	if (s[0] == '-' || s[0] == '+')
		s++;
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
	return (true);
}

bool	parse_and_push_int(char *s, t_stack *stack)
{
	int		*content;

	content = (int *)malloc(sizeof(int));
	if (!content)
		return (false);
	if (!parse_int(s, content))
	{
		free(content);
		return (false);
	}
	if (ft_is_inside_stack(stack, *content))
	{
		free(content);
		return (false);
	}
	push(stack, content);
	return (true);
}

bool	parse_unique_string(char *string, t_stack *stack)
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
	i = size - 1;
	while (i >= 0)
	{
		if (!parse_and_push_int(words[i], stack))
		{
			free_array((void **)words, size);
			return (false);
		}
		i--;
	}
	free_array((void **)words, size);
	return (true);
}

bool	parse_args(int size, char *words[], t_stack *stack)
{
	int		i;
	bool	state;
	char	*string;

	if (size == 1)
	{
		string = ft_strtrim(words[1], " ");
		if (!string)
			return (false);
		state = parse_unique_string(string, stack);
		free (string);
		return (state);
	}
	i = size;
	while (i > 0)
	{
		if (!parse_and_push_int(words[i], stack))
		{
			return (false);
		}
		i--;
	}
	return (true);
}
