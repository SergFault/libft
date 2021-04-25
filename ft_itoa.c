/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:40:39 by sergey            #+#    #+#             */
/*   Updated: 2021/04/23 20:43:45 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rank(unsigned int num)
{
	unsigned int rank;

	if (!(num))
		return (1);
	rank = 0;
	while (num > 0)
	{
		rank++;
		num /= 10;
	}
	return (rank);
}

static int	ft_getsign(int num)
{
	if (num < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int				rank;
	int				sign;
	unsigned int	num;
	char			*ret;

	sign = ft_getsign(n);
	num = n;
	if (sign)
		num = -n;
	rank = ft_rank(num) + sign;
	if (!(ret = (char*)malloc(sizeof(char) * (rank + 1))))
		return (0);
	ret[rank] = '\0';
	while (num > 9)
	{
		ret[rank-- - 1] = (num % 10) + ('0' + 0);
		num /= 10;
	}
	ret[rank-- - 1] = (num) + ('0' + 0);
	num = 0;
	if (sign)
		ret[rank - 1] = '-';
	return (ret);
}
