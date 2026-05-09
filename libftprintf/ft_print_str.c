/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:59:05 by tsito             #+#    #+#             */
/*   Updated: 2026/05/02 14:36:44 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	else
	{
		while (s[len])
			len++;
		return (write(1, s, len));
	}
}
