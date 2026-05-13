/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:52:43 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 17:47:34 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	pos = get_pos_by_min_index(a);
	size = stack_size(a);
	while (pos != 0)
	{
		if (pos <= size / 2)
		{
			ra(a);
			pos--;
		}
		else
		{
			rra(a);
			pos++;
			if (pos == size)
				pos = 0;
		}
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_three(t_stack *a)
{
	if (a->top->index > a->top->next->index
		&& a->top->index > a->top->next->next->index)
		ra(a);
	else if (a->top->next->index > a->top->index
		&& a->top->next->index > a->top->next->next->index)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}
