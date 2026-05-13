/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:52:43 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 19:50:22 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
