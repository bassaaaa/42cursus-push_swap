/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:57:55 by tsito             #+#    #+#             */
/*   Updated: 2026/04/27 18:57:56 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	buf = (unsigned char *)b;
	i = 0;
	while (i < len)
		buf[i++] = (unsigned char)c;
	return (b);
}
