/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:34:07 by jkasongo          #+#    #+#             */
/*   Updated: 2021/09/02 01:47:35 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap two integers, take pointers
void	ft_swap_i(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	heapify(int *arr, int n, int i)
{
	int	largest;
	int	l;
	int	r;

	largest = i;
	l = (2 * i) + 1;
	r = (2 * i) + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		ft_swap_i(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void	heap_sort(int arr[], int n)
{
	int	i;

	i = n / 2 - 1;
	while (i >= 0)
	{
		heapify(arr, n, i);
		i--;
	}
	i = n - 1;
	while (i > 0)
	{
		ft_swap_i(&arr[0], &arr[i]);
		heapify(arr, i, 0);
		i--;
	}
}

int	ft_find_median_value(int arr[], int n)
{
	int	median;
	int	a;
	int	b;

	heap_sort(arr, n);
	median = 0;
	if ((n % 2) != 0)
		median = arr[(n / 2)];
	else
	{
		a = arr[(n / 2)];
		b = arr[(n / 2) + 1];
		median = (a + b) / 2;
	}
	return (median);
}

int	ft_find_quart_value(int arr[], int n)
{
	int	quart;
	int	a;
	int	b;

	heap_sort(arr, n);
	quart = 0;
	if ((n % 2) != 0)
		quart = arr[(n / 4)];
	else
	{
		a = arr[(n / 4)];
		b = arr[(n / 4) + 1];
		quart = (a + b) / 2;
	}
	return (quart);
}
