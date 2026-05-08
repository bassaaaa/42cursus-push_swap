/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:43:27 by tsito             #+#    #+#             */
/*   Updated: 2026/04/17 13:54:29 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*append_node(t_list **result, t_list **tail, void *mapped,
		void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(mapped);
	if (!new_node)
	{
		del(mapped);
		ft_lstclear(result, del);
		return (NULL);
	}
	if (!*tail)
		*result = new_node;
	else
		(*tail)->next = new_node;
	*tail = new_node;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tail;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	tail = NULL;
	while (lst)
	{
		if (!append_node(&result, &tail, f(lst->content), del))
			return (NULL);
		lst = lst->next;
	}
	return (result);
}
