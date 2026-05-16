/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/16 00:00:00 by tsito            ###   ########.fr       */
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

int	parse_options(char **args, t_input *input, size_t *i)
{
	t_option	option;

	*i = 0;
	input->option = OPTION_ADAPTIVE;
	input->bench = 0;
	while (args[*i] && ft_strncmp(args[*i], "--", 2) == 0)
	{
		if (ft_strncmp(args[*i], "--bench", ft_strlen("--bench") + 1) == 0)
			input->bench = 1;
		else
		{
			option = get_option(args[*i]);
			if (option == OPTION_INVALID)
				return (0);
			input->option = option;
		}
		(*i)++;
	}
	return (1);
}
