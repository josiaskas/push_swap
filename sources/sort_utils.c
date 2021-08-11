/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:55:56 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/11 18:17:53 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted_asc(int arr[], int n)
{
	bool	status;
	int		i;

	i = 0;
	status = false;
	while (i < (n - 1))
	{
		if (arr[i] > arr[i + 1])
			break ;
		i++;
	}
	if (i == (n - 1))
		status = true;
	return (status);
}

bool	is_sorted_desc(int arr[], int n)
{
	bool	status;
	int		i;

	i = 0;
	status = false;
	while (i < (n - 1))
	{
		if (arr[i] < arr[i + 1])
			break ;
		i++;
	}
	if (i == (n - 1))
		status = true;
	return (status);
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

int	type_of_sort(int arr[], int n)
{
	if (is_sorted_asc(arr, n))
		return (1);
	if (is_sorted_desc(arr, n))
		return (2);
	return (3);
}
