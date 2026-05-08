/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:57:06 by tsito             #+#    #+#             */
/*   Updated: 2026/04/10 21:28:01 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
	write(fd, pos, &buf[11] - pos);
}
