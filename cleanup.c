/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:00:00 by tsito             #+#    #+#             */
/*   Updated: 2026/05/16 00:00:00 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	size_t	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	free_input(t_input *input, char **args, int status)
{
	free(input->values);
	free_args(args);
	return (status);
}

int	free_all(t_stack *a, t_stack *b, t_input *input, char **args)
{
	free_stack(a);
	free_stack(b);
	free(input->values);
	free_args(args);
	return (0);
}
