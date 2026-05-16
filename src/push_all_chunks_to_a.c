/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_chunks_to_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:49:32 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 18:42:47 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *b, int target_index)
{
	t_node	*n;
	int		pos;

	n = b->top;
	pos = 0;
	while (n)
	{
		if (n->index == target_index)
			return (pos);
		n = n->next;
		pos++;
	}
	return (0);
}

static void	push_chunk_to_a(t_stack *a, t_stack *b, int total, int chunk_max)
{
	int	pos;

	pos = find_pos(b, chunk_max);
	if (pos <= total / 2)
		while (pos-- > 0)
			rrb(b);
	else
	{
		pos = total - pos;
		while (pos-- > 0)
			rb(b);
	}
	pa(a, b);
}

void	push_all_chunks_to_a(t_stack *a, t_stack *b, int total)
{
	int	chunk_count_value;
	int	chunk_size_value;
	int	chunk_min;
	int	chunk_max;
	int	i;

	chunk_count_value = get_chunk_count(total);
	chunk_size_value = get_chunk_size(total, chunk_count_value);
	i = chunk_count_value - 1;
	while (i >= 0)
	{
		chunk_min = i * chunk_size_value;
		chunk_max = get_chunk_max(chunk_min, total, chunk_size_value);
		while (chunk_max >= chunk_min)
		{
			push_chunk_to_a(a, b, total, chunk_max);
			chunk_max--;
			total--;
		}
		i--;
	}
}
