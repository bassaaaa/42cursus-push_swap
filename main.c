/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:37:22 by tsito             #+#    #+#             */
/*   Updated: 2026/05/18 18:34:49 by tsito            ###   ########.fr       */
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
		radix_sort(a, b);
}

static void	sort_by_option(t_stack *a, t_stack *b, t_input *input,
		double disorder)
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
		radix_sort(a, b);
	else
		sort_adaptive(a, b, disorder);
}

static void	run_sort(t_stack *a, t_stack *b, t_input *input)
{
	double	disorder;

	set_index(a);
	disorder = compute_disorder(a);
	init_benchmark();
	sort_by_option(a, b, input, disorder);
	if (input->bench)
		print_benchmark(input, disorder);
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
	run_sort(&a, &b, &input);
	return (free_all(&a, &b, &input, args));
}
