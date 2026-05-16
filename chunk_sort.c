/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:36:46 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/16 18:42:02 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	total_size;

	total_size = get_stack_size(a);
	push_all_chunks_to_b(a, b, total_size);
	push_all_chunks_to_a(a, b, total_size);
}
