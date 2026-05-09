/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:58:13 by tsito             #+#    #+#             */
/*   Updated: 2026/05/02 19:56:38 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	char			buf[18];
	char			*pos;
	unsigned long	addr;

	if (!p)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)p;
	pos = &buf[18];
	while (addr)
	{
		*(--pos) = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	*--pos = 'x';
	*--pos = '0';
	return (write(1, pos, &buf[18] - pos));
}
