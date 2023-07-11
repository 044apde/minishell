/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:16:43 by shikim            #+#    #+#             */
/*   Updated: 2023/03/23 22:33:57 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	int		compared_value;
	char	*temp_s1;
	char	*temp_s2;

	temp_s1 = (char *)s1;
	temp_s2 = (char *)s2;
	while (n-- > 0 && (*temp_s1 != '\0' || *temp_s2 != '\0'))
	{
		compared_value = (unsigned char)*temp_s1 - (unsigned char)*temp_s2;
		if (compared_value != 0)
			return (compared_value);
		temp_s1++;
		temp_s2++;
	}
	return (0);
}
