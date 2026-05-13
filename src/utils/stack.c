/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:31:51 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 17:32:04 by tsito            ###   ########.fr       */
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
