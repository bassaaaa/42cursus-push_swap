/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/19 00:53:54 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_option	get_option(char *str)
{
	if (ft_strncmp(str, "--adaptive", ft_strlen("--adaptive") + 1) == 0)
		return (OPTION_ADAPTIVE);
	if (ft_strncmp(str, "--simple", ft_strlen("--simple") + 1) == 0)
		return (OPTION_SIMPLE);
	if (ft_strncmp(str, "--medium", ft_strlen("--medium") + 1) == 0)
		return (OPTION_MEDIUM);
	if (ft_strncmp(str, "--complex", ft_strlen("--complex") + 1) == 0)
		return (OPTION_COMPLEX);
	return (OPTION_INVALID);
}

static int	is_bench(char *str)
{
	return (ft_strncmp(str, "--bench", ft_strlen("--bench") + 1) == 0);
}

static int	set_bench(t_input *input, int *has_bench)
{
	if (*has_bench)
		return (0);
	input->bench = 1;
	*has_bench = 1;
	return (1);
}

static int	set_strategy_option(char *str, t_input *input, int *has_strategy)
{
	t_option	option;

	if (*has_strategy)
		return (0);
	option = get_option(str);
	if (option == OPTION_INVALID)
		return (0);
	input->option = option;
	*has_strategy = 1;
	return (1);
}

int	parse_options(char **args, t_input *input, size_t *i)
{
	int	has_bench;
	int	has_strategy;

	*i = 0;
	input->option = OPTION_ADAPTIVE;
	input->bench = 0;
	has_bench = 0;
	has_strategy = 0;
	while (args[*i] && ft_strncmp(args[*i], "--", 2) == 0)
	{
		if (is_bench(args[*i]))
		{
			if (!set_bench(input, &has_bench))
				return (0);
		}
		else if (!set_strategy_option(args[*i], input, &has_strategy))
			return (0);
		(*i)++;
	}
	return (1);
}
