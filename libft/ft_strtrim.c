/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:38:22 by shikim            #+#    #+#             */
/*   Updated: 2023/04/04 20:11:25 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (*s1 == '\0')
	{
		trimmed_str = (char *)malloc(1);
		if (trimmed_str == 0)
			return (0);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		++start;
	while (end > start && ft_strchr(set, s1[end]))
		--end;
	trimmed_str = (char *)malloc(end - start + 2);
	if (trimmed_str == 0)
		return (0);
	ft_memmove(trimmed_str, &s1[start], end - start + 1);
	trimmed_str[end - start + 1] = '\0';
	return (trimmed_str);
}
