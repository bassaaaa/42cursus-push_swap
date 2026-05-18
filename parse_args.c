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
	size_t	i;

	if (!args || !args[0] || !input)
		return (0);
	if (!parse_options(args, input, &i))
		return (0);
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
