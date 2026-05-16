/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:49:32 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 16:10:33 by ksaotome         ###   ########.fr       */
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

static void	search_chunks_in_b(t_stack *a, t_stack *b, int total_size)
{
	int	pos;

	pos = find_pos(b, chunk_max);
	if (pos <= total_size / 2)
		while (pos-- > 0)
			rb(b);
	else
	{
		pos = total_size - pos;
		while (pos-- > 0)
			rrb(b);
	}
	pa(a, b);
	(*current_size)--;
}

void	push_chunks_to_a(t_stack *a, t_stack *b, int total_size)
{
	int	i;
	int	chunk_min;
	int	chunk_max;
	int	chunk_count;
	int	chunk_size;

	chunk_count = chunk_count(total_size);
	chunk_size = chunk_size(total_size, chunk_count);
	i = chunk_count - 1;
	while (i >= 0)
	{
		chunk_min = i * chunk_size;
		chunk_max = chunk_max_search(chunk_min, total_size, chunk_size);
		while (chunk_max >= chunk_min)
		{
			search_chunks_in_b(a, b, total_size);
			chunk_max--;
		}
		total_size--;
		i--;
	}
}
