/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:36:46 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/15 22:10:16 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	root;

	if (nb <= 0 || nb > INT_MAX)
		return (0);
	root = 0;
	while (nb > root * root)
	{
		root++;
		if (nb == root * root)
			return (root);
	}
	return (root - 1);
}

void	push_a(t_stack *a, t_stack *b, int total_size, int chunk_count, int chunk_size)
{
	int	i;
	int n;

	i = 0;
	n = chunk_size;
	while ()
	{
		while (n--)
		{
			if (i <= a->top->index && i + chunk_size > a->top->index)
				pb(a, b);
			if (a->top->index >= ) 
			{
				//TOPない場合脱出する
			}
			ra(a);
		}
		i += chunk_size;
		n = chunk_size;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_count;
	int	chunk;

	total_size = get_stack_size(a);
	chunk_count = ft_sqrt(total_size);
	chunk_size = (total_size + chunk_count - 1) / chunk_count;

	push_a(a, b, total_size, chunk_size, chunk_count)
}

