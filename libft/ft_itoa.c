/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:48:22 by shikim            #+#    #+#             */
/*   Updated: 2023/04/03 13:26:26 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	absoluitize(int n)
{
	unsigned int	dst;

	if (n < 0)
		dst = (long long)n * -1;
	else
		dst = (long long)n;
	return (dst);
}

static int	measure_size(int n)
{
	int			size;
	long long	num;

	size = 1;
	if (n < 0)
	{
		++size;
		num = (long long)n * -1;
	}
	else
		num = (long long)n;
	while (num >= 10)
	{
		++size;
		num = num / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*dst;
	int				dst_size;
	unsigned int	num;

	num = absoluitize(n);
	dst_size = measure_size(n);
	dst = (char *)malloc(dst_size + 1);
	if (dst == 0)
		return (0);
	dst[dst_size] = '\0';
	while (dst_size-- > 1)
	{
		dst[dst_size] = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
		dst[0] = '-';
	else
		dst[0] = (num % 10) + 48;
	return (dst);
}
