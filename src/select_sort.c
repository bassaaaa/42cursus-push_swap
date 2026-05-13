/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:25:30 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/13 19:50:36 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 int	find_min_index(t_stack *a)
{
	t_node	*n;
	int		pos;
	int		min_pos;
	int		min_idx;

	n = a->top;
	pos = 0;
	min_pos = 0;
	min_idx = INT_MAX;
	while (n)
	{
		if (n->index < min_idx)
		{
			min_idx = n->index;
			min_pos = pos;
		}
		n = n->next;
		pos++;
	}
	return (min_pos);
}

static void	rotate_to_top(t_stack *stack, int pos)
{
	int	size;

	size = get_stack_size(stack);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

void	select_sort(t_stack *a, t_stack *b)
{
	int		pos;
	size_t	size;

	while (get_stack_size(a) > 1)
	{
		pos = find_min_index(a);
		rotate_to_top(a, pos);
		pb(a, b);
	}
	while (b->top)
		pa(a, b);
}