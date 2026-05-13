/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chepest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:06:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 18:12:25 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	get_total_cost(t_node *node)
{
	if ((node->cost_a > 0 && node->cost_b > 0)
		|| (node->cost_a < 0 && node->cost_b < 0))
		return (max_int(abs_int(node->cost_a), abs_int(node->cost_b)));
	return (abs_int(node->cost_a) + abs_int(node->cost_b));
}

t_node	*get_cheapest(t_stack *b)
{
	t_node	*cur;
	t_node	*cheapest;
	int		min_cost;
	int		cost;

	cur = b->top;
	cheapest = cur;
	min_cost = get_total_cost(cur);
	while (cur)
	{
		cost = get_total_cost(cur);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = cur;
		}
		cur = cur->next;
	}
	return (cheapest);
}
