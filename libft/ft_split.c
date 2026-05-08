/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:29:21 by tsito             #+#    #+#             */
/*   Updated: 2026/04/23 22:15:33 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*dup_word(char const *s, char c)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

static char	**free_split(char **split, int count)
{
	while (count > 0)
	{
		count--;
		free(split[count]);
	}
	free(split);
	return (NULL);
}

static char	**fill_split(char **split, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		split[j] = dup_word(&s[i], c);
		if (!split[j])
			return (free_split(split, j));
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (fill_split(split, s, c));
}
