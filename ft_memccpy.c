/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:47:55 by sergey            #+#    #+#             */
/*   Updated: 2021/04/23 18:43:36 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char *d;
	unsigned char ch;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	ch = (unsigned char)c;
	while (n && *s != ch)
	{
		*(d++) = *(s++);
		n--;
	}
	if (n == 0)
		return (0);
	else
		*(d++) = *(s++);
	return (d);
}
