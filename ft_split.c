/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:41:03 by sergey            #+#    #+#             */
/*   Updated: 2021/04/24 19:31:24 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_datasnaps(const char *str, char del)
{
	size_t c;

	c = 0;
	while (*str)
	{
		if (*str == del)
			while (*str == del && *str)
				str++;
		else
		{
			c++;
			while (*str != del && *str)
				str++;
		}
	}
	return (c);
}

static int		ft_parce(char **str, const char *src, char del,
					size_t d_snaps)
{
	size_t size;
	size_t str_n;

	str_n = 0;
	while (str_n < d_snaps)
	{
		size = 0;
		while (*src == del && *src)
			src++;
		while (*src != del && *src)
		{
			src++;
			size++;
		}
		if (!(str[str_n] = (char*)malloc(sizeof(char) * (size + 1))))
			return (0);
		src -= size;
		while (size--)
			ft_strlcat(str[str_n], src++, ft_strlen(str[str_n]) + 2);
		str_n++;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	data_snaps;

	data_snaps = ft_datasnaps(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (data_snaps + 1))))
		return (0);
	ft_parce(ret, s, c, data_snaps);
	ret[data_snaps] = 0;
	return (ret);
}
