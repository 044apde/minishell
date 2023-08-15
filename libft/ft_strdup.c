/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:10:54 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 14:51:00 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1) + 1;
	dst = (char *)malloc(sizeof(char) * len_s1);
	if (dst == 0)
		return (0);
	ft_memmove(dst, s1, len_s1);
	return (dst);
}
