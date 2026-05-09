/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:01:21 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/09 16:51:58 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *stk)
{
	t_node	*f;
	t_node	*s;
	int		temp_value;
	int		temp_index;

	if (!stk->top || !stk->top->next)
		return (0);
	f = stk->top;
	s = stk->top->next;

	temp_value = f->value;
	f->value = s->value;
	s->value = temp_value;

	temp_index = f->index;
	f->index = s->index;
	s->index = temp_index;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a->top || !a->top->next || !b->top || !b->top->next)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
