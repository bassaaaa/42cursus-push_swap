/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:25:30 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 20:05:24 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_stack *a, t_stack *b)
{
	while (get_stack_size(a) > 1)
	{
		rotate_min_to_top(a);
		pb(a, b);
	}
	while (b->top)
		pa(a, b);
}
