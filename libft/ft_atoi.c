/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:56:21 by tsito             #+#    #+#             */
/*   Updated: 2026/04/27 18:56:23 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_space(const char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\v'
		|| **str == '\f' || **str == '\r')
		(*str)++;
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static long	ft_strtol(const char *str)
{
	int		sign;
	long	result;
	int		digit;

	skip_space(&str);
	sign = get_sign(&str);
	result = 0;
	while (ft_isdigit(*str))
	{
		digit = (*str - '0') * sign;
		if (sign > 0 && result > (LONG_MAX - digit) / 10)
			return (LONG_MAX);
		if (sign < 0 && result < (LONG_MIN - digit) / 10)
			return (LONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str));
}
