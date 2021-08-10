/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:22:37 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/09 20:33:31 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap two integers
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

void	heapSort(int arr[], int n)
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

	heapSort(arr, n);
	median = 0;
	if ((n % 2) != 0)
		median = arr[((n - 1) / 2)];
	else
	{
		a = arr[(n / 2) - 1];
		b = arr[(n / 2)];
		median = (a + b) / 2;
	}
	return (median);
}
