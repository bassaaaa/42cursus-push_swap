/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:56:25 by tsito             #+#    #+#             */
/*   Updated: 2026/05/02 14:37:47 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char *base)
{
	char	buf[8];
	char	*pos;

	pos = &buf[8];
	if (n == 0)
		*(--pos) = '0';
	while (n)
	{
		*(--pos) = base[n % 16];
		n /= 16;
	}
	return (write(1, pos, &buf[8] - pos));
}
