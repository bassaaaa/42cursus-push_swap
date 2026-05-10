/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:03:26 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/10 19:00:27 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stk)
{
	t_node	*current;
	t_node	*next;

	current = stk->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stk->top = NULL;
}

t_node	*init_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

int	init_stack(t_stack *a, t_input *input)
{
	t_node	*node;
	size_t	i;
	size_t	size;
	t_node	*tail;

	a->top = NULL;
	a->name = 'a';
	tail = NULL;
	i = 0;
	size = input->size;
	while (i < size)
	{
		node = init_node(input->values[i++]);
		if (!node)
		{
			free_stack(a);
			return (0);
		}
		if (!a->top)
			a->top = node;
		else
			tail->next = node;
		tail = node;
	}
	return (1);
}
