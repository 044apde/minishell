/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:30:41 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 15:46:33 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*replace_to_env(char *s)
{
	char	*result;
	char	*dangling;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '$')
		++i;
	j = i;
	while (s[j] != ' ' && s[j] != '"' && s[j] != '\0')
		++j;
	dangling = s;
	s[i] = '\0';
	result = ft_strjoin(s, "'ENV'");
	s = s + j;
	temp = result;
	result = ft_strjoin(result, s);
	free(dangling);
	free(temp);
	return (result);
}

int	is_operator(char *s)
{
	if (compare_str(s, "|") == TRUE)
		return (TRUE);
	else if (compare_str(s, "<") == TRUE)
		return (TRUE);
	else if (compare_str(s, ">") == TRUE)
		return (TRUE);
	else if (compare_str(s, "<<") == TRUE)
		return (TRUE);
	else if (compare_str(s, ">>") == TRUE)
		return (TRUE);
	else if (s == NULL)
		return (TRUE);
	else
		return (FALSE);
}
