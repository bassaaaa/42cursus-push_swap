/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:40:19 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 16:40:50 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_joined_len(int ac, char **av)
{
	size_t	len;
	int		i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		if (i + 1 < ac)
			len += 1;
		i++;
	}
	return (len);
}

static char	*join_args(int ac, char **av)
{
	char	*joined;
	size_t	len;
	int		i;

	len = get_joined_len(ac, av);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strlcat(joined, av[i], len + 1);
		if (i + 1 < ac)
			ft_strlcat(joined, " ", len + 1);
		i++;
	}
	return (joined);
}

char	**join_and_split(int ac, char **av)
{
	char	*joined;
	char	**args;

	joined = join_args(ac, av);
	if (!joined)
		return (NULL);
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}
