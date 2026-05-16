/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_search_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:50:37 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 16:03:10 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_chunks_in_a(t_stack *a, t_stack *b,
	int chunk_min, int chunk_max)
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

void	push_chunks_to_b(t_stack *a, t_stack *b, int total_size)
{
	int	chunk_min;
	int	chunk_max;
	int	chunk_count_value;
	int	chunk_size_value;
	int	i;

	chunk_count_value = chunk_count(total_size);
	chunk_size_value = chunk_size(total_size, chunk_count_value);
	i = 0;
	while (i < chunk_count_value)
	{
		chunk_min = i * chunk_size_value;
		chunk_max = chunk_max_search(chunk_min, total_size, chunk_size_value);
		search_chunks_in_a(a, b, chunk_min, chunk_max);
		i++;
	}
}
