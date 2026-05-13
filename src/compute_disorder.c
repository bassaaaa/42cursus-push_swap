/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:30:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 22:30:14 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;
	int		size;

	size = get_stack_size(a);
	if (size < 2)
		return (0.0);
	mistakes = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	total_pairs = (long)size * (size - 1) / 2;
	return ((double)mistakes / (double)total_pairs);
}
