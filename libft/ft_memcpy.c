/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:39:21 by shikim            #+#    #+#             */
/*   Updated: 2023/03/22 21:29:16 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (dst == 0 && src == 0)
		return (0);
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	while (n-- > 0)
		*dest++ = *source++;
	return (dst);
}
