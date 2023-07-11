/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:50 by shikim            #+#    #+#             */
/*   Updated: 2023/03/22 15:35:05 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*char_dst;
	char const	*char_src;

	char_dst = dst;
	char_src = src;
	if (char_dst == 0 && char_src == 0)
		return (0);
	if (char_dst < char_src)
	{
		while (len-- > 0)
			*char_dst++ = *char_src++;
	}
	else if (char_dst > char_src)
	{
		char_dst += len;
		char_src += len;
		while (len-- > 0)
			*--char_dst = *--char_src;
	}
	return (dst);
}
