/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:49:32 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 19:49:54 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	pos = get_min_pos(a);
	size = get_stack_size(a);
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
