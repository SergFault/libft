/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:36:28 by sergey            #+#    #+#             */
/*   Updated: 2021/04/27 12:14:14 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dptr = dest;
	while (n--)
		*((unsigned char *) dptr++) = *((unsigned char *) src++);
	return (dest);
}
