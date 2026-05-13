/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 18:47:54 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_to_top(t_stack *a)
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
}
