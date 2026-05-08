/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:21:30 by tsito             #+#    #+#             */
/*   Updated: 2026/04/15 15:48:57 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (n_len <= len && *haystack)
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
