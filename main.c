/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:37:22 by tsito             #+#    #+#             */
/*   Updated: 2026/05/16 19:58:34 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	sort_adaptive(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
		select_sort(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		turk_sort(a, b);
}

static void	exec_sort(t_stack *a, t_stack *b, t_input *input, double disorder)
{
	int	size;

	if (is_sorted(a))
		return ;
	size = get_stack_size(a);
	if (size == 2)
		sa(a);
	else if (input->option == OPTION_SIMPLE)
		select_sort(a, b);
	else if (input->option == OPTION_MEDIUM)
		chunk_sort(a, b);
	else if (input->option == OPTION_COMPLEX)
		turk_sort(a, b);
	else
		sort_adaptive(a, b, disorder);
}

int	main(int ac, char **av)
{
	char	**args;
	t_input	input;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	args = join_and_split(ac, av);
	if (!args || !parse_args(args, &input))
	{
		free_args(args);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!init_stack(&a, &input))
		return (free_input(&input, args, 1));
	b.top = NULL;
	b.name = 'b';
	set_index(&a);
	exec_sort(&a, &b, &input, compute_disorder(&a));
	return (free_all(&a, &b, &input, args));
}
