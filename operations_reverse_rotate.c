/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:30:47 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 16:40:04 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	prev = stack->top;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		print_op("rra", OP_RRA);
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		print_op("rrb", OP_RRB);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || !a->top->next || !b->top || !b->top->next)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	print_op("rrr", OP_RRR);
}
