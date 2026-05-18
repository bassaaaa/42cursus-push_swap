/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/18 21:32:47 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = get_stack_size(a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
            i++;
		}
		while (b->top)
			pa(a, b);
		bit++;
	}
}
