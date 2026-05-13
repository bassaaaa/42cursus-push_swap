/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:08:16 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 18:07:56 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_pos(t_stack *a, int b_index)
{
	t_node	*cur;
	int		target_index;
	int		target_pos;

	cur = a->top;
	target_index = INT_MAX;
	target_pos = 0;
	while (cur)
	{
		if (cur->index > b_index && cur->index < target_index)
		{
			target_index = cur->index;
			target_pos = cur->pos;
		}
		cur = cur->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	return (get_min_pos(a));
}

static void	set_target_pos(t_stack *a, t_stack *b)
{
	t_node	*b_node;

	b_node = b->top;
	while (b_node)
	{
		b_node->target_pos = get_target_pos(a, b_node->index);
		b_node = b_node->next;
	}
}

static void	set_costs(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	cur = b->top;
	while (cur)
	{
		cur->cost_a = get_cost(cur->target_pos, size_a);
		cur->cost_b = get_cost(cur->pos, size_b);
		cur = cur->next;
	}
}

static void	sort_remaining(t_stack *a, t_stack *b)
{
	if (stack_size(a) == 5)
		sort_five(a, b);
	else if (stack_size(a) == 4)
		sort_four(a, b);
	else if (stack_size(a) == 3)
		sort_three(a);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int		mid_index;
	t_node	*cheapest;

	mid_index = stack_size(a) / 2;
	while (stack_size(a) >= 6)
	{
		if (a->top->index < mid_index)
			pb(a, b);
		else
			ra(a);
	}
	sort_remaining(a, b);
	while (b->top)
	{
		set_pos(a);
		set_pos(b);
		set_target_pos(a, b);
		set_costs(a, b);
		cheapest = get_cheapest(b);
		move_cheapest(a, b, cheapest);
		pa(a, b);
	}
	rotate_min_to_top(a);
}
