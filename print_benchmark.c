/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/18 18:02:32 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_name(t_option option)
{
	if (option == OPTION_SIMPLE)
		return ("Simple");
	if (option == OPTION_MEDIUM)
		return ("Medium");
	if (option == OPTION_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*get_complexity(t_input *input, double disorder)
{
	if (input->option == OPTION_SIMPLE)
		return ("O(n^2)");
	if (input->option == OPTION_MEDIUM)
		return ("O(n√n)");
	if (input->option == OPTION_COMPLEX)
		return ("O(n log n)");
	if (disorder < 0.2)
		return ("O(n^2)");
	if (disorder < 0.5)
		return ("O(n sqrt(n))");
	return ("O(n log n)");
}

static void	print_disorder(double disorder)
{
	int	percent;

	percent = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	if (percent % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(percent % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_benchmark(t_input *input, double disorder)
{
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putstr_fd(get_strategy_name(input->option), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(get_complexity(input, disorder), 2);
	ft_putstr_fd("\n[bench] total_ops:  ", 2);
	ft_putnbr_fd(get_total_ops(), 2);
	ft_putstr_fd("\n", 2);
	print_swap_push_counts();
	print_rotate_counts();
}
