/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:32:27 by sergey            #+#    #+#             */
/*   Updated: 2021/04/25 14:55:26 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_locate_first(char const *s1, char const *set)
{
	size_t	first;

	first = 0;
	while (s1[first])
	{
		if (!(ft_strchr(set, s1[first])))
			return (first);
		else
			first++;
	}
	return (0);
}

static size_t	ft_locate_last(char const *s1, char const *set)
{
	size_t	last;
	size_t	c;

	last = 0;
	c = 0;
	while (s1[c])
	{
		if (!(ft_strchr(set, s1[c])))
			last = c++;
		else
			c++;
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*trimmed;

	if (!set || !s1)
		return (NULL);
	if (!set[0] || !s1[0])
		return (ft_strdup(""));
	first = ft_locate_first(s1, set);
	last = ft_locate_last(s1, set);
	if ((first == last) && (ft_strchr(set, s1[first])))
		return (ft_strdup(""));
	trimmed = (char *)malloc(sizeof(char) * ((last - first + 1) + 1));
	if (!(trimmed))
		return (0);
	ft_strlcpy(trimmed, s1 + first, (last - first + 1) + 1);
	return (trimmed);
}
