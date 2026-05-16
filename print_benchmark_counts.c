/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark_counts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/16 00:00:00 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_swap_push_counts(void)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(get_op_count(OP_SA), 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(get_op_count(OP_SB), 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(get_op_count(OP_SS), 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(get_op_count(OP_PA), 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(get_op_count(OP_PB), 2);
	ft_putstr_fd("\n", 2);
}

void	print_rotate_counts(void)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(get_op_count(OP_RA), 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(get_op_count(OP_RB), 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(get_op_count(OP_RR), 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(get_op_count(OP_RRA), 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(get_op_count(OP_RRB), 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(get_op_count(OP_RRR), 2);
	ft_putstr_fd("\n", 2);
}
