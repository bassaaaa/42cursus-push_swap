/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:25:39 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 14:31:23 by tsito            ###   ########.fr       */
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

static size_t	get_values_size(char **args, size_t i)
{
	size_t	size;

	size = 0;
	while (args[i])
	{
		size++;
		i++;
	}
	return (size);
}

static int	has_duplicate_value(int *values, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		if (values[j] == values[i])
			return (1);
		j++;
	}
	return (0);
}

static int	fill_values(char **args, size_t start, t_input *input)
{
	size_t	i;
	long	num;

	i = 0;
	while (i < input->size)
	{
		if (!is_valid_int_format(args[start + i]))
			return (0);
		num = ft_strtol(args[start + i]);
		if (num < INT_MIN || INT_MAX < num)
			return (0);
		input->values[i] = (int)num;
		if (has_duplicate_value(input->values, i))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(char **args, t_input *input)
{
	size_t		i;
	t_option	option;

	if (!args || !args[0])
		return (0);
	i = 0;
	input->option = OPTION_ADAPTIVE;
	option = get_option(args[i]);
	if (option != OPTION_INVALID)
	{
		input->option = option;
		i++;
	}
	input->size = get_values_size(args, i);
	if (input->size == 0)
		return (0);
	input->values = malloc(sizeof(int) * input->size);
	if (!input->values)
		return (0);
	if (fill_values(args, i, input))
		return (1);
	free(input->values);
	input->values = NULL;
	return (0);
}
