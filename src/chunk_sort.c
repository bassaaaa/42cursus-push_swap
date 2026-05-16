/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:36:46 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 15:30:19 by ksaotome         ###   ########.fr       */
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
static int	max_seach(int chunk_min, int total_size, int chunk_size)
{
	int	chunk_max;

	chunk_max = chunk_min + chunk_size - 1;
	if (chunk_max >= total_size)
		chunk_max = total_size - 1;
	return (chunk_max);
}

static void	search_push_a(t_stack *a, t_stack *b, int total_size, int chunk_size, int chunk_count)
{
	int i;
	int n;
	int chunk_min;
	int chunk_max;

	i = 0;
	while (i < chunk_count)
	{
		n = 0;
		chunk_min = i * chunk_size;
		chunk_max = max_search(chunk_min, total_size, chunk_size);
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
		i++;
	}
}

static void	search_push_b(t_stack *a, t_stack *b, int total_size, int chunk_size, int chunk_count)
{
	int i;
	int chunk_min;
	int chunk_max;
	int pos;
	int current_size;

	i = chunk_count - 1;
	current_size = total_size;
	while (i >= 0)
	{
		chunk_min = i * chunk_size;
		chunk_max = max_search(chunk_min, total_size, chunk_size);
		while (chunk_max >= chunk_min)
		{
			pos = find_pos(b, chunk_max);
			if (pos <= current_size / 2)
				while (pos-- > 0)
					rb(b);
			else
			{
				pos = current_size - pos;
				while (pos-- > 0)
					rrb(b);
			}
			pa(a, b);
			current_size--;
			chunk_max--;
		}
		i--;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_count;
	int	chunk;

	total_size = get_stack_size(a);
	chunk_count = ft_sqrt(total_size);
	chunk_size = (total_size + chunk_count - 1) / chunk_count;
	search_push_a(a, b, total_size, chunk_size, chunk_count);
	search_push_b(a, b, total_size, chunk_size, chunk_count);
}

