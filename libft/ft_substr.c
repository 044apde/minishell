/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:27:34 by shikim            #+#    #+#             */
/*   Updated: 2023/03/31 16:49:16 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_len_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_substr;
	size_t	len_s;

	len_s = ft_strlen(s);
	len_substr = len_s - start;
	if (len_s <= start)
		return (0);
	else if (len_substr <= len)
		return (len_substr);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_substr;
	size_t	index_substr;

	index_substr = 0;
	len_substr = check_len_substr(s, start, len);
	substr = (char *)malloc(len_substr + 1);
	if (substr == 0)
		return (0);
	if (*s == '\0' || len == 0 || len_substr == 0)
	{
		substr[0] = '\0';
	}
	else
	{
		s += start;
		while (*s != '\0' && len-- > 0)
		{
			substr[index_substr] = *s;
			++index_substr;
			++s;
		}
		substr[index_substr] = '\0';
	}
	return (substr);
}
