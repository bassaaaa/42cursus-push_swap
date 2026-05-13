/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:02:08 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 18:47:49 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_unindexed(t_stack *stack)
{
	t_node	*cur;
	int		min;

	cur = stack->top;
	min = INT_MAX;
	while (cur)
	{
		if (cur->index < 0 && cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	return (min);
}

static t_node	*find_node_by_value(t_stack *stack, int value)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->value == value)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	set_index(t_stack *stack)
{
	t_node	*node;
	int		i;
	int		min;
	int		size;

	i = 0;
	size = get_stack_size(stack);
	while (i < size)
	{
		min = get_min_unindexed(stack);
		node = find_node_by_value(stack, min);
		if (node)
			node->index = i;
		i++;
	}
}
