/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:00:09 by tsito             #+#    #+#             */
/*   Updated: 2026/04/03 17:17:24 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (len < sub_len)
		sub_len = len;
	sub = malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[start], sub_len);
	sub[sub_len] = '\0';
	return (sub);
}
