/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/16 00:00:00 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_benchmark	*get_benchmark(void)
{
	static t_benchmark	benchmark;

	return (&benchmark);
}

void	print_op(char *name, t_operation op)
{
	get_benchmark()->counts[op]++;
	ft_printf("%s\n", name);
}

void	init_benchmark(void)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
		get_benchmark()->counts[i++] = 0;
}

int	get_op_count(t_operation op)
{
	return (get_benchmark()->counts[op]);
}

int	get_total_ops(void)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
		total += get_op_count(i++);
	return (total);
}
