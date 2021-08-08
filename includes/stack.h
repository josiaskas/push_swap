/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:52:41 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/08 16:11:50 by jkasongo         ###   ########.fr       */
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
// push value on the stack return 1 (0 in case of failure)
int				*push(t_stack *stack, int value);
// return the value in error MIN_VALUE is returned
int				pop(t_stack *stack);
// return the head value without destroying the node (error = MIN_VALUE)
int				peak(t_stack *stack);
// init stack current to 0 (to the head)
int				start_iteration(t_stack *stack);
// greedy get the next ellement according to current value in t_stack
t_stack_node	*get_next(t_stack *stack);
// return 1 if empty / 0 all other cases
int				is_empty(t_stack *stack);
// swap the first 2 elements at the top of stack (nothing if stack->length <= 1)
int				swap(t_stack *stack);
// shift up all elements of the stack return 1 (0 if errors)
int				rotate(t_stack *stack);
#endif