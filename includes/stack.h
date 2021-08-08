/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:52:41 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/08 14:34:20 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define MIN_VALUE -2147483648
# define MAX_VALUE 2147483647
typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	int				length;
	int				current;
	t_stack_node	*head;
	t_stack_node	*bottom;

}	t_stack;

t_stack			*create_stack(void);
int				*push(t_stack *stack, int value);
int				pop(t_stack *stack);
int				peak(t_stack *stack);
int				start_iteration(t_stack *stack);
int				*get_next(t_stack *stack);
int				is_empty(t_stack *stack);
#endif