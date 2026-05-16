/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:40:21 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 18:18:37 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int total_size)
{
	return (ft_sqrt(total_size));
}

int	get_chunk_size(int total_size, int chunk_count)
{
	return ((total_size + chunk_count - 1) / chunk_count);
}

int	get_chunk_max(int chunk_min, int total, int chunk_size)
{
	int	chunk_max;

	chunk_max = chunk_min + chunk_size - 1;
	if (chunk_max >= total)
		chunk_max = total - 1;
	return (chunk_max);
}
