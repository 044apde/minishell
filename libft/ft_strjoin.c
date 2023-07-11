/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:42 by shikim            #+#    #+#             */
/*   Updated: 2023/04/03 13:29:32 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	char	*origin_joined_str;
	size_t	len_joined_str;

	len_joined_str = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc(len_joined_str + 1);
	origin_joined_str = joined_str;
	if (joined_str == 0)
		return (0);
	while (*s1 != '\0')
		*joined_str++ = *s1++;
	while (*s2 != '\0')
		*joined_str++ = *s2++;
	*joined_str = '\0';
	return (origin_joined_str);
}
