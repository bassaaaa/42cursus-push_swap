/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:40:21 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 16:12:27 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_count(int total_size)
{
	return (ft_sqrt(total_size));
}

int	chunk_size(int total_size, int chunk_count)
{
	return ((total_size + chunk_count - 1) / chunk_count);
}

int	chunk_max_search(int chunk_min, int total, int chunk_size)
{
	int	chunk_max;

	chunk_max = chunk_min + chunk_size - 1;
	if (chunk_max >= total)
		chunk_max = total - 1;
	return (chunk_max);
}
