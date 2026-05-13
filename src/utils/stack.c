/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:31:51 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 18:01:31 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*node;

	size = 0;
	node = stack->top;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}

int	get_min_pos(t_stack *stack)
{
	t_node	*cur;
	int		pos;
	int		min_pos;
	int		min_index;

	pos = 0;
	min_pos = 0;
	cur = stack->top;
	min_index = cur->index;
	while (cur)
	{
		if (cur->index < min_index)
		{
			min_index = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

void	set_pos(t_stack *stack)
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

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}
