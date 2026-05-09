/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:57:32 by tsito             #+#    #+#             */
/*   Updated: 2026/05/02 14:37:42 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	unsigned int	num;
	char			buf[11];
	char			*pos;

	if (n < 0)
		num = -(unsigned int)n;
	else
		num = (unsigned int)n;
	pos = &buf[11];
	if (num == 0)
		*(--pos) = '0';
	while (num)
	{
		*(--pos) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(--pos) = '-';
	return (write(1, pos, &buf[11] - pos));
}
