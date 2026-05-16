/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:50:27 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 14:21:56 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int_format(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
