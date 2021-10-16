# push_swap
Push_swap a 42 project on sort algorithms.

This goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## The Game
The game is composed of 2 stacks named a and b.
- To start with:

  - stack_a contains a random number of either positive or negative numbers without any duplicates.
  - stack_b is empty

The goal is to sort in ascending order numbers into stack a.

## operations at your disposal:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
