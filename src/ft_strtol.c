/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:30:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 14:30:00 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	ft_strtol(const char *str)
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
