/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:37:22 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 15:50:27 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	t_input	input;
	size_t	i;

	if (ac < 2)
		return (0);
	args = join_and_split(ac, av);
	if (!args || !parse_args(args, &input))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (i < input.size)
		ft_printf("%d\n", input.values[i++]);
	free(input.values);
	return (0);
}
