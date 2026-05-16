/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:17:27 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 16:34:44 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

static int	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	first = stack->top;
	stack->top = stack->top->next;
	first->next = NULL;
	last = last_node(stack->top);
	last->next = first;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		print_op("ra", OP_RA);
}

void	rb(t_stack *b)
{
	if (rotate(b))
		print_op("rb", OP_RB);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || !a->top->next || !b->top || !b->top->next)
		return ;
	rotate(a);
	rotate(b);
	print_op("rr", OP_RR);
}
