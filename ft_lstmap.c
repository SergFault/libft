/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:34:59 by sergey            #+#    #+#             */
/*   Updated: 2021/04/26 09:44:57 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_el;

	if (!lst || !f || !lst->content)
		return (NULL);
	new_el = ft_lstnew(f(lst->content));
	if (!(new_el))
		return (NULL);
	new_lst = new_el;
	lst = lst->next;
	while (lst)
	{
		new_el = ft_lstnew(f(lst->content));
		if (!(new_el))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_el);
	}
	return (new_lst);
}
