/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:52:44 by shikim            #+#    #+#             */
/*   Updated: 2023/08/05 22:44:08 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_dollar_index(char *token)
{
	int	index;

	index = -1;
	while (token[++index] != '\0')
	{
		if (token[index] == '$')
			return (index);
	}
	return (ERROR);
}

int	find_sep_index(char *token, int dollar_index)
{
	int	index;

	index = dollar_index;
	while (token[++index] != '\0')
	{
		if (is_sep(token[index]) == TRUE)
			return (index);
	}
	return (ERROR);
}

char	*make_substitute(char *token)
{
	char	*new_token;
	int		dollar_index;
	int		sep_index;

	dollar_index = find_dollar_index(token);
	if (dollar_index == -1)
		return (NULL);
	printf("dollar: %d\n", dollar_index);
	sep_index = find_sep_index(token, dollar_index);
	printf("sep: %d\n", sep_index);
	if (sep_index == ERROR)
		return (NULL);
	return (new_token);
}