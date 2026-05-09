/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:25:48 by tsito             #+#    #+#             */
/*   Updated: 2026/05/02 14:37:12 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	char	buf[10];
	char	*pos;

	pos = &buf[10];
	if (n == 0)
		*(--pos) = '0';
	while (n)
	{
		*(--pos) = n % 10 + '0';
		n /= 10;
	}
	return (write(1, pos, &buf[10] - pos));
}
