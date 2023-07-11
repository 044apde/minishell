/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:20:46 by marvin            #+#    #+#             */
/*   Updated: 2023/04/01 16:39:04 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len_s;
	int		index;
	char	*dst;

	len_s = ft_strlen(s);
	index = 0;
	dst = (char *)malloc(len_s + 1);
	if (dst == 0)
		return (0);
	while (index < len_s)
	{
		dst[index] = f(index, s[index]);
		++index;
	}
	dst[index] = '\0';
	return (dst);
}
