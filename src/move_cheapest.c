/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:30:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 18:30:00 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_same_way(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_a_to_target(t_stack *a, int cost)
{
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
}

static void	rotate_b_to_top(t_stack *b, int cost)
{
	while (cost > 0)
	{
		rb(b);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b);
		cost++;
	}
}

void	move_cheapest(t_stack *a, t_stack *b, t_node *cheapest)
{
	int	cost_a;
	int	cost_b;

	if (!cheapest)
		return ;
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	rotate_same_way(a, b, &cost_a, &cost_b);
	rotate_a_to_target(a, cost_a);
	rotate_b_to_top(b, cost_b);
}
