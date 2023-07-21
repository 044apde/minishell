/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:10:54 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 15:02:16 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*dst;

	len_s1 = ft_strlen(s1) + 1;
	dst = (char *)malloc(sizeof(char) * len_s1);
	if (dst == 0)
		return (0);
	ft_memmove(dst, s1, len_s1);
	return (dst);
}
