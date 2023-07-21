/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:30:41 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 22:22:00 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*replace_to_env(char *s, t_env_list *env_list)
{
	char	*result;
	char	*replace;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '$')
		++i;
	j = i;
	while (s[j] != ' ' && s[j] != '"' && s[j] != '\0')
		++j;
	replace = get_env(env_list, ft_substr(s, i, j - i));
	if (replace == NULL)
	{
		free(s);
		return ("\n");
	}
	result = ft_strjoin(ft_substr(s, 0, i), replace);
	temp = result;
	result = ft_strjoin(result, s + j);
	free(temp);
	free(s);
	return (result);
}

int	is_operator(char *s)
{
	if (s == NULL)
		return (TRUE);
	else if (compare_str(s, "|") == TRUE)
		return (TRUE);
	else if (compare_str(s, "<") == TRUE)
		return (TRUE);
	else if (compare_str(s, ">") == TRUE)
		return (TRUE);
	else if (compare_str(s, "<<") == TRUE)
		return (TRUE);
	else if (compare_str(s, ">>") == TRUE)
		return (TRUE);
	else
		return (FALSE);
}
