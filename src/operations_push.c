/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:01:46 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 16:14:50 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!dst || !src || !src->top)
		return (0);
	tmp = src->top;
	src->top = src->top->next;
	tmp->next = dst->top;
	dst->top = tmp;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pb\n");
}
