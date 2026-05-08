/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:47:52 by tsito             #+#    #+#             */
/*   Updated: 2026/04/23 22:16:47 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_digits(long value, char *result, size_t len)
{
	result[len] = '\0';
	if (value == 0)
		result[0] = '0';
	if (value < 0)
	{
		result[0] = '-';
		value = -value;
	}
	while (value > 0)
	{
		result[--len] = value % 10 + '0';
		value /= 10;
	}
	return (result);
}

static size_t	count_digits(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	return (fill_digits(n, str, len));
}
