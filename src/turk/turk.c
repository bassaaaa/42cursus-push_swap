/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:08:16 by tsito             #+#    #+#             */
/*   Updated: 2026/05/12 21:00:11 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_pos(t_stack *a, t_stack *b)
{
	int		target_index;
	int		target_pos;
	t_node	*cur_a;
	t_node	*cur_b;

	cur_b = b->top;
	while (cur_b)
	{
		cur_a = a->top;
		target_index = INT_MAX;
		target_pos = 0;
		while (cur_a)
		{
			if (cur_a->index > cur_b->index && cur_a->index < target_index)
			{
				target_index = cur_a->index;
				target_pos = cur_a->pos;
			}
			cur_a = cur_a->next;
		}
		if (target_index == INT_MAX)
			cur_b->target_pos = get_pos_by_min_index(a);
		else
			cur_b->target_pos = target_pos;
		cur_b = cur_b->next;
	}
}

static void	set_pos(t_stack *stack)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = stack->top;
	while (cur)
	{
		cur->pos = i++;
		cur = cur->next;
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	mid_index;

	mid_index = stack_size(a) / 2;
	while (stack_size(a) >= 6)
	{
		if (a->top->index < mid_index)
			pb(a, b);
		else
			ra(a);
	}
	while (1)
	{
		set_pos(b);
	}
}
