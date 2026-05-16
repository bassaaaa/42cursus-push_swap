/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_chunks_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:50:37 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 18:57:04 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_min,
	int chunk_max)
{
	int	n;

	n = 0;
	while (n < chunk_max - chunk_min + 1)
	{
		if (a->top->index >= chunk_min && a->top->index <= chunk_max)
		{
			pb(a, b);
			n++;
		}
		else
			ra(a);
	}
}

void	push_all_chunks_to_b(t_stack *a, t_stack *b, int total)
{
	int	chunk_min;
	int	chunk_max;
	int	chunk_count_value;
	int	chunk_size_value;
	int	i;

	chunk_count_value = get_chunk_count(total);
	chunk_size_value = get_chunk_size(total, chunk_count_value);
	i = 0;
	while (i < chunk_count_value)
	{
		chunk_min = i * chunk_size_value;
		chunk_max = get_chunk_max(chunk_min, total, chunk_size_value);
		push_chunk_to_b(a, b, chunk_min, chunk_max);
		i++;
	}
}
