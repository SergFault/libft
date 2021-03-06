/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:23:14 by sergey            #+#    #+#             */
/*   Updated: 2021/09/26 20:54:57 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skipspaces(const char *nptr)
{
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		   || *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	return (nptr);
}

static const char	*getsign(const char *nptr, int *minuses)
{
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			*minuses = -1;
		nptr++;
	}
	return (nptr);
}

int	ft_atoi(const char *nptr)
{
	int				minuses;
	int				rank;
	long long int	r;

	r = 0;
	rank = 0;
	minuses = 1;
	nptr = skipspaces(nptr);
	nptr = getsign(nptr, &minuses);
	while (*nptr >= '0' && *nptr <= '9')
	{
		r = r * 10 + (*nptr++ - ('0'));
		rank++;
		if ((r * minuses) > INT_MAX || (r * minuses) < INT_MIN)
		{
			ft_putstr_fd("Error\n", STDOUT_FILENO);
			exit(1);
		}
	}
	return (r * (minuses));
}
