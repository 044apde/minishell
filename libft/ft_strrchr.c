/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:23:23 by shikim            #+#    #+#             */
/*   Updated: 2023/03/23 15:49:14 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*temp_s;
	char	temp_c;

	temp_s = (char *)s;
	index = ft_strlen(temp_s) + 1;
	temp_s += index - 1;
	temp_c = (char) c;
	while (index-- > 0)
	{
		if (*temp_s == temp_c)
			return (temp_s);
		temp_s--;
	}
	return (0);
}
