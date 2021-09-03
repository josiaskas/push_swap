/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:20:26 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/02 20:56:23 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

// size (number of args without the first one), args and the stack to push to
bool	parse_args(int size, char *words[], t_stack *stack);

//operations

bool	do_sa(t_stack *stack_a);
bool	do_sb(t_stack *stack_b);
// switch both but if one length < 2 do only sa or sb
bool	do_ss(t_stack *stack_a, t_stack *stack_b);
bool	do_pa(t_stack *stack_a, t_stack *stack_b);
bool	do_pb(t_stack *stack_a, t_stack *stack_b);
bool	do_ra(t_stack *stack_a);
bool	do_rb(t_stack *stack_b);
// rotate both but if one length < 2 do only ra or rb
bool	do_rr(t_stack *stack_a, t_stack *stack_b);
bool	do_rra(t_stack *stack_a);
bool	do_rrb(t_stack *stack_b);
// rev rotate both but if one length < 2 do only ra or rb
bool	do_rrr(t_stack *stack_a, t_stack *stack_b);

// return the median of an array of int;
int		ft_find_median_value(int arr[], int n);

void	heap_sort(int arr[], int n);
// help mapping the stack without changing the content (only for int array map)
int		do_nothing(void *content, int index);
// print two stacks on fd 1
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
// partitions with mediane
void	partitionate_mediane(t_stack *a, t_stack *b);
void	partitionate_quarter(t_stack *a, t_stack *b);
void	partitionate_quarter_to_a(t_stack *a, t_stack *b);

void	move_to_a(t_stack *a, t_stack *b, int max);
void	move_to_b(t_stack *a, t_stack *b, int max);
int		from_bottom_c(t_stack *a, int max);
int		from_top_c(t_stack *a, int max);

// partitions with each chunks max
void	partionate_in_n_chunks(t_stack *a, t_stack *b, int n);
void	partionate_in_n_chunks_b(t_stack *a, t_stack *b, int n);
//push back all data in order
void	reorder_partitions(t_stack *a, t_stack *b);

void	big_sort(t_stack *a, t_stack *b);

// particular
void	big_sort_it_asc(t_stack *a, t_stack *b);
void	small_sort_two(t_stack *a);
void	small_sort3(t_stack *a);
void	small_sort4(t_stack *a, t_stack *b);
void	small_sort5(t_stack *a, t_stack *b);
#endif
