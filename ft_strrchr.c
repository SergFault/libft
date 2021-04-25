/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:14:17 by sergey            #+#    #+#             */
/*   Updated: 2021/04/24 12:33:16 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;
	char *last_ptr;

	last_ptr = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			last_ptr = ptr;
		ptr++;
	}
	if (*ptr == '\0' && *ptr == c)
		return (ptr);
	return (last_ptr);
}
