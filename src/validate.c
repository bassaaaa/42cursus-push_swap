/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:50:27 by tsito             #+#    #+#             */
/*   Updated: 2026/05/08 22:32:22 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(char *str)
{
	size_t	i;
	long	num;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	num = ft_strtol(str);
	return (INT_MIN <= num && num <= INT_MAX);
}

static int	is_valid_option(char *str)
{
	if (ft_strncmp(str, "--adaptive", ft_strlen("--adaptive") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "--simple", ft_strlen("--simple") + 1) == 0)
		return (2);
	if (ft_strncmp(str, "--medium", ft_strlen("--medium") + 1) == 0)
		return (3);
	if (ft_strncmp(str, "--complex", ft_strlen("--complex") + 1) == 0)
		return (4);
	return (0);
}

static int	has_duplicate(char **args, size_t i)
{
	size_t	j;
	long	num;

	num = ft_strtol(args[i]);
	j = 0;
	if (is_valid_option(args[j]))
		j++;
	while (j < i)
	{
		if (ft_strtol(args[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

int	validate_args(char **args)
{
	size_t	i;

	if (!args || !args[0])
		return (0);
	i = 0;
	if (is_valid_option(args[i]))
		i++;
	if (!args[i])
		return (0);
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (0);
		if (has_duplicate(args, i))
			return (0);
		i++;
	}
	return (1);
}
