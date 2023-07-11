/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:12:50 by shikim            #+#    #+#             */
/*   Updated: 2023/03/24 16:18:35 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*max_len;
	char	len_needle;

	max_len = (char *)haystack + len;
	if (len == (size_t)-1)
		max_len = (char *)haystack + ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	if (*needle != '\0')
	{
		if (len == 0 || *haystack == '\0')
			return (0);
		while (haystack + len_needle <= max_len)
		{
			if (ft_strncmp(haystack, needle, len_needle) == 0)
			{
				return ((char *)haystack);
			}
			haystack++;
		}
		return (0);
	}
	return ((char *)haystack);
}
