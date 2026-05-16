/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:33:43 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 14:33:49 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	root;

	if (nb <= 0 || nb > INT_MAX)
		return (0);
	root = 0;
	while (nb > root * root)
	{
		root++;
		if (nb == root * root)
			return (root);
	}
	return (root - 1);
}
